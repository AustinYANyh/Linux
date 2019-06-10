#!/usr/bin/env python
#-*- coding:utf-8 -*-
import requests

import os

url='https://pvp.qq.com/web201605/js/herolist.json'

head = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.109 Safari/537.36'}
response = requests.get(url, headers=head)
hero_list = response.json()


hero_name=list(map(lambda x:x['cname'], hero_list))

hero_number=list(map(lambda x:x['ename'],hero_list))

def save_IMG():
        num = 0
        #逐一遍历英雄
        for i in hero_number:
              for sk_num in range(15):
                  heroskin_links = 'http://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/'\
                  +str(i)+'/'+str(i)+'-bigskin-'+str(sk_num)+'.jpg'
                  hl = requests.get(heroskin_links)
                  if hl.status_code == 200:
                      with open(hero_name[num] + str(sk_num) + '.jpg', 'wb') as f:
                          f.write(hl.content)
              num+=1

save_IMG()
