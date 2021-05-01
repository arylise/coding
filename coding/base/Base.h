//
// Created by Arylise on 2021/4/30.
//

#ifndef CODING_BASE_H
#define CODING_BASE_H

#define __print(n) std::cout<<n
#define __println(n) std::cout<<n<<std::endl
#define __println_ std::cout<<std::endl

#define __printArr(arr, n) for(int __i=0;__i<n;__i++)__print(arr[__i]<<' ');__println_
#define __printArrBetween(arr, i, j) for(int __i=i;__i<=j;__i++)__print(arr[__i]<<' ');__println_
#define __printMat(mat, n, m) for(int __i=0;__i<n;__i++){for(int __j=0;__j<m;__j++)__print(mat[__i][__j]<<' ');__println_;}
#define __printMatBetween(mat, i1, i2, j1, j2) for(int __i=i1;__i<=i2;__i++){for(int __j=j1;__j<=j2;__j++)__print(mat[__i][__j]<<' ');__println_;}

#define __scan(n) std::cin>>n

#define __scanArr(arr, n) for(int __i=0;__i<n;__i++)__scan(arr[__i])
#define __scanArrFrom(arr, n, in) for(int __in=0,__i=0;__i<n;__i++)arr[__i]=in[__in++]
#define __scanArrBetween(arr, i, j) for(int __i=i;__i<=j;__i++)__scan(arr[__i])
#define __scanArrBetweenFrom(arr, i, j, in) for(int __in=0,__i=i;__i<=j;__i++)arr[__i]=in[__in++]
#define __scanMat(mat, n, m) for(int __i=0;__i<n;__i++)for(int __j=0;__j<m;__j++)__scan(mat[__i][__j])
#define __scanMatFrom(mat, n, m, in) for(int __in=0,__i=0;__i<n;__i++)for(int __j=0;__j<m;__j++)mat[__i][__j]=in[__in++]
#define __scanMatBetween(mat, i1, i2, j1, j2) for(int __i=i1;__i<=i2;__i++)for(int __j=j1;__j<=j2;__j++)__scan(mat[__i][__j])
#define __scanMatBetweenFrom(mat, i1, i2, j1, j2, in) for(int __in=0,__i=i1;__i<=i2;__i++)for(int __j=j1;__j<=j2;__j++)mat[__i][__j]=in[__in++]

#define __creatArr(type, arr, n) arr=new type[n]
#define __creatIntArr(arr, n) arr=new int[n]
#define __creatMat(type, mat, n, m) mat=new type*[n];for(int __i=0;__i<n;__i++)mat[__i]=new type[m]
#define __creatIntMat(mat, n, m) mat=new int*[n];for(int __i=0;__i<n;__i++)mat[__i]=new int[m]

#define __setIntArrTo(arr, n, num) __creatIntArr(arr, n);for(int __i=0;__i<n;__i++)arr[__i]=num
#define __setIntMatTo(mat, n, m, num) __creatIntMat(mat, n, m);for(int __i=0;__i<n;__i++)for(int __j=0;__j<m;__j++)mat[__i][__j]=num


#define __initArr(type, arr, n) __creatArr(type,arr,n);__scanArr(arr,n)
#define __initArrFrom(type, arr, n, in) __creatArr(type,arr,n);__scanArrFrom(arr,n,in)
#define __initIntArr(arr, n) __creatIntArr(arr,n);__scanArr(arr,n)
#define __initIntArrFrom(arr, n, in) __creatIntArr(arr,n);__scanArrFrom(arr,n,in)
#define __initMat(type, mat, n, m) __creatMat(type,mat,n,m);__scanMat(mat,n,m)
#define __initMatFrom(type, mat, n, m, in) __creatMat(type,mat,n,m);__scanMatFrom(mat,n,m,in)
#define __initIntMat(mat, n, m) __creatIntMat(mat,n,m);__scanMat(mat,n,m)
#define __initIntMatFrom(mat, n, m, in) __creatIntMat(mat,n,m);__scanMatFrom(mat,n,m,in)

#endif //CODING_BASE_H
