# concurent::Heap
Is rather naive implementation of lock-free reference counting pointers forward iterable container. Pointer placed in the concurent::Heap stays there until it referenced by returned unique\_ptr and any additional shared\_ptr(s) obtained by dereferencing concurent::Heap iterators.

### Motivation
One of the common approaches when using [Boost.Asio](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio.html) or Networking TS [N4656](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4656.pdf) is to create connection/session object in accept handler and pass it wrapped in std::shared\_ptr to subsequent handlers. This approach allows to keep connection/session object alive until it used by any ongoing operation handler. See [Boost.Asio examples](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/examples/cpp11_examples.html):
[Chat](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/example/cpp11/chat/chat_server.cpp), 
[Echo](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/example/cpp11/echo/async_tcp_echo_server.cpp)
or [HTTP Server](http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/example/cpp11/http/server/server.cpp) as example of such approach.

But sometimes it desirable to perform some additional operation on opened connection.
concurent::Heap simplifies such tasks by allowing iterate its elements thread safe manner.

here is slightly modified [Echo](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/example/cpp11/echo/async_tcp_echo_server.cpp) example.
```
#include "concurent/heap.hpp"

class server
{
public:
  server(boost::asio::io_context& io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
  {
    do_accept();
  }

  void drop_connections()
  {
	for(auto& session : sessions_) // iterating concurent::Heap is thread safe
	   sesion->close(); // make sure this operation is thread safe 
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket)
        {
          if (!ec)
          {
            //std::make_shared<session>(std::move(socket))->start();

			// session will be automaticaly removed from heap when all refferences to it are gone
			auto session = std::shared_ptr{sessions_.emplace(std::move(socket))}; 
			session->start();  
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  concurent::Heap<session> sessions_;
};

```

### Requirements
 - c++11 suported compiler (clang 3.6+, gcc 4.8.5+, msvc-14+ )
 - [boost](http://www.boost.org) ([MPL](http://www.boost.org/doc/libs/1_66_0/libs/mpl/doc/index.html), [Fusion](http://www.boost.org/doc/libs/1_66_0/libs/fusion/doc/html/), [Compressed_Pair](http://www.boost.org/doc/libs/1_66_0/libs/utility/doc/html/compressed_pair.html))

