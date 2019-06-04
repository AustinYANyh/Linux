#!/usr/bin/env python
# -*- coding:utf-8 -*-

start=1;
#while True:
   #if start==51:
      #break
   #print start*2
   #start+=1


#while True:
    #if start==100:
        #break
    #if start%2 ==1:
        #print start
    #start+=1

sum=0
while True:
    if start==101:
        break
    if start%2==1:
        sum=sum+start
    if start%2==0:
        sum=sum-start
    start+=1
print sum

