#include "mainwindow.h"

#include <QApplication>

//#include<assert.h>
//#include<complex.h>
//#include<ctype.h>
//#include<errno.h>
//#include<fenv.h>
//#include<float.h>
//#include<inttypes.h>
//#include<iso646.h>
//#include<limits.h>
//#include<locale.h>
//#include<math.h>
//#include<setjmp.h>
//#include<signal.h>
//#include<stdalign.h>
//#include<stdarg.h>
//#include<stdatomic.h>
//#include<stdbool.h>
//#include<stddef.h>
//#include<stdint.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdnoreturn.h>
//#include<string.h>
//#include<tgmath.h>
//#include<threads.h>
//#include<time.h>
//#include<uchar.h>
//#include<wchar.h>
//#include<wctype.h>

#include <functional>
#include <iostream>

struct MMM
{
    template <typename _Tp, typename _Up>
    auto     operator()(_Tp&& __t, _Up&& __u) const -> decltype(__t + __u)
    {
        return std::forward<_Tp>(__t) + std::forward<_Up>(__u);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

 //   std::cout <<__PRETTY_FUNCTION__<<' '<<"\n";

    return a.exec();
}
