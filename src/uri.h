#ifndef URI_H__
#define URI_H__

#include <string>

struct Uri<T>
{
public:
T QueryString, Path, Protocol, Host, Port;

static Uri<T> Parse(const T &uri);
};

#endif // URI_H__