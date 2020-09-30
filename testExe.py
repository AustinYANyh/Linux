import os
import threading


def startexe(exename):
    os.chdir("E:\\NewWork\\BodorThinker\\projects\\hmi\\BodorThinker2000\\bin\\Debug")
    os.system(exename)


def main():
    while True:
        name = "BodorThinker2000.exe"
        t1 = threading.Thread(target=startexe, args=(u'BodorThinker2000.exe',))
        t1.start()

        order = int(input("输入指令:"))
        if order == 1:
            os.system("Taskkill /im "+name)
            continue


if __name__ == '__main__':
    main()
