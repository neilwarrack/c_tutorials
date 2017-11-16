Hi Sarah. I get a warning when I compile this, as you might see... (see warning at bottom of this msg)...

Since it compiles correctly - I think it means that I have an old c++ compiler which is using an extension that has some feature that behaves like C++11 (this is what I gather from stackexchange, etc.). 
If this is so, how do you get an updated c++ compiler? I've looked around online and can't seem to find the answers... Isn't it strange that a new Mac from 2017 has a compiler that is from pre-2011? Is that just the way g++ is? Cheers, Neil.

The warning is:

main.cc:109:10: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]

PS. 
If I type: 
g++ --version 
It returns:
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.0.0 (clang-900.0.38)
Target: x86_64-apple-darwin17.2.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
