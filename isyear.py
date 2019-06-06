#!/usr/bin/env python
#-*- coding:utf-8 -*-

def isyear(a):
    if a%400==0:
        print("a是闰年")
    elif a%100==0 and a%4==0:
        print("a是闰年")
    else:
        print("a不是闰年")

while True:
    a=int(input("请输入年份:"))
    isyear(a)

