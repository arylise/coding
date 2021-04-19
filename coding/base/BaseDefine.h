//
// Created by Arylise on 2021/4/7.
//

#ifndef CODING_BASEDEFINE_H
#define CODING_BASEDEFINE_H

#include <iostream>

#define __creatN(type, n) type n;std::cin>>n
#define __cinN(n) std::cin>>n
#define __creatInt(n) int n;std::cin>>n
#define __creatArray(type, a, n) int n;std::cin>>n;type a[n];for(int __i=0;__i<n;__i++) std::cin>>a[__i]
#define __cinArray(a, n) for(int __i=0;__i<n;__i++) std::cin>>a[__i]
#define __creatIntArray(a, n) int n;std::cin>>n;int a[n];for(int __i=0;__i<n;__i++) std::cin>>a[__i]
#define __coutN(n) std::cout<<n<<std::endl
#define __coutArray(a, n) for(int __i=0;__i<n;__i++) std::cout<<a[__i]<<" ";std::cout<<std::endl
#define __coutArrayFrom(a, i, j) for(int __i=i;__i<=j;__i++) std::cout<<a[__i]<<" ";std::cout<<std::endl
#define __range(min, n, max) (n>=min&&n<=max)
#endif //CODING_BASEDEFINE_H
