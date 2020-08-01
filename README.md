# svmcpp
implementation of SVM based on [libsvm code](https://www.csie.ntu.edu.tw/~cjlin/libsvm/) but using modern C++20 and optimized for high preformance

The code in this repo on libsvm (see the link above). 
The main issues that I have with libsvm is that is writing with no regard for modern hardware arch as well as not taking advanteges of modern C++. 
This means that you can pass invalid parameters, you are using none cache friendly data structures and it would be hard to parralelized the code.
