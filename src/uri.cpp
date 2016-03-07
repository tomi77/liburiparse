#include <algorithm>    // std::find

using namespace std;

template <typename T>
struct Uri
{
public:
    T QueryString, Path, Protocol, Host, Port;

    static Uri<T> Parse(const T &uri)
    {
	Uri<T> result;

	typedef typename T::const_iterator iterator_t;

	if (uri.length() == 0)
	    return result;

	iterator_t uriEnd = uri.end();

	// get query start
	iterator_t queryStart = find(uri.begin(), uriEnd, L'?');

	// protocol
	iterator_t protocolStart = uri.begin();
	iterator_t protocolEnd = find(protocolStart, uriEnd, L':');            //"://");

	if (protocolEnd != uriEnd)
	{
	    T prot = &*(protocolEnd);
	    if ((prot.length() > 3) && (prot.substr(0, 3) == L"://"))
	    {
		result.Protocol = T(protocolStart, protocolEnd);
		protocolEnd += 3;   //      ://
	    }
	    else
		protocolEnd = uri.begin();  // no protocol
	}
	else
	    protocolEnd = uri.begin();  // no protocol

	// host
	iterator_t hostStart = protocolEnd;
	iterator_t pathStart = find(hostStart, uriEnd, L'/');  // get pathStart

	iterator_t hostEnd = find(protocolEnd, 
	    (pathStart != uriEnd) ? pathStart : queryStart,
	    L':');  // check for port

	result.Host = T(hostStart, hostEnd);

	// port
	if ((hostEnd != uriEnd) && ((&*(hostEnd))[0] == L':'))  // we have a port
	{
	    hostEnd++;
	    iterator_t portEnd = (pathStart != uriEnd) ? pathStart : queryStart;
	    result.Port = T(hostEnd, portEnd);
	}

	// path
	if (pathStart != uriEnd)
	    result.Path = T(pathStart, queryStart);

	// query
	if (queryStart != uriEnd)
	    result.QueryString = T(queryStart, uri.end());

	return result;

    }   // Parse
};  // uri