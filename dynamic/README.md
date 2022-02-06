## <div align="center">Dynamic Library Commands</div>

Compile files: `make -f makefile.basic library`

Install dynamic library in system: `make -f makefile.basic install`

Remove .o files: `make -f makefile.basic clean`

Remove .o and .so files: `make -f makefile.basic distclean`

<br/>

**NOTE: To import the library add `#include <basic.h>` in your code.**
