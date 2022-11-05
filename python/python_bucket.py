# -*- coding: utf-8 -*-

class Bucket:
    def __init__(self,volume):
        self.volume = volume
        self.now_v = 0

    def Full_Bucket(self):
        self.now_v = self.volume

    def Purge_Bucket(self):
        self.now_v = 0

    def Pour(self,other_Bucket):
        other_Bucket.now_v += self.now_v
        if other_Bucket.now_v > other_Bucket.volume:
            self.now_v = other_Bucket.now_v - other_Bucket.volume
            other_Bucket.now_v = other_Bucket.volume
        else:
            self.now_v = 0

def print_h(v1,now_v1,v2,now_v2,v3,now_v3):
    for i in range(1,v1+1):
        print("    "+str(v1+1 - i)+"|",end = "")
        for j in range(1,5):
            if v1+1-i > now_v1:
                print(" ",end = "")
            else:
                print("W",end = "")
        print("|",end = "")
        print("     ",end = "")

        if v1+1-i>v2:
            print(" ",end = "")
        else:
            print(str(v1+1 - i)+"|",end = "")
        for j in range(1,5):
            if v1+1-i > now_v2:
                print(" ",end = "")
            else:
                print("W",end = "")
        if v1+1-i>v2:
            print(" ",end = "")
        else:
            print("|",end = "")

        print("     ",end = "")
        if v1+1-i>v3:
            print(" ",end = "")
        else:
            print(str(v1+1 - i)+"|",end = "")
        for j in range(1,5):
            if v1+1-i > now_v3:
                print(" ",end = "")
            else:
                print("W",end = "")
        if v1+1-i>v3:
            print(" ",end = "")
        else:
            print("|",end = "")
        print("")
    print("    ",end = "")
    for i in range(1,4):
        print(" +",end = "")
        for j in range(1,5):
            print("-",end = "")
        print("+     ",end = "")

    print("")
    print("       ",end = "")
    print(str(v1)+"L"+"          "+str(v2)+"L"+"          "+str(v3)+"L")


def print_bucket_v(b1,b2,b3):
    #print(str(b1.now_v)+" "+str(b2.now_v)+" "+str(b3.now_v))
    print_h(b1.volume,b1.now_v,b2.volume,b2.now_v,b3.volume,b3.now_v)

def print_notice():
    print("你可以：")
    print(" (F)注满水桶")
    print(" (E)清空水桶")
    print(" (P)从一个通向另一个桶倒水")
    print(" (Q)退出")

def Bucket_game():
    print("水桶游戏开始............")
    print("目标三桶之一的水量为4L")
    B1 = Bucket(8)
    B2 = Bucket(5)
    B3 = Bucket(3)
    print_bucket_v(B1,B2,B3)
    count = 0
    while True:
        print_notice()
        enter = input().upper()
        if enter == 'F':
            enter = input("选择一个桶 8，5，3，或QUIT(Q):\n").upper()
            while enter:
                if enter == 'Q':
                    break
                elif enter == '8':
                    B1.Full_Bucket()
                    count+=1
                    print_bucket_v(B1,B2,B3)
                    break
                elif enter == '5':
                    B2.Full_Bucket()
                    count+=1
                    print_bucket_v(B1,B2,B3)
                    break
                elif enter == '3':
                    B3.Full_Bucket()
                    count+=1
                    print_bucket_v(B1,B2,B3)
                    break
                else:
                    enter = input("您需要选择一个桶或Q退出：\n").upper()
            continue
        elif enter == 'E':
            enter = input("选择一个桶8，5，3，或QUIT(Q):\n").upper()
            while enter:
                if enter == 'Q':
                    break
                elif enter == '8':
                    B1.Purge_Bucket()
                    count+=1
                    print_bucket_v(B1,B2,B3)
                    break
                elif enter == '5':
                    B2.Purge_Bucket()
                    count+=1
                    print_bucket_v(B1,B2,B3)
                    break
                elif enter == '3':
                    B3.Purge_Bucket()
                    count+=1
                    print_bucket_v(B1,B2,B3)
                    break
                else:
                    enter = input("您需要选择一个桶8，5，3，或Q退出：\n").upper()
            continue
        elif enter == 'P':
            enter = input("选择一个桶8，5，3，或QUIT(Q):\n").upper()
            while enter:
                if enter == 'Q':
                    break
                elif enter == '8':
                    enter = input("选择一个被注入的桶5，3，或QUIT(Q):\n").upper()
                    while enter:
                        if enter == 'Q':
                            break
                        elif enter == '5':
                            B1.Pour(B2)
                            count+=1
                            break
                        elif enter == '3':
                            B1.Pour(B3)
                            count+=1
                            break
                        else:
                            enter = input("您需要选择一个桶5，3，或Q退出：\n").upper()
                    print_bucket_v(B1,B2,B3)
                    if B1.now_v == 4 or B2.now_v == 4 or B3.now_v == 4:
                        print("恭喜！，你一共用了"+str(count)+"步！")
                        return True
                    break
                elif enter == '5':
                    enter = input("选择一个被注入的桶8，3，或QUIT(Q):\n").upper()
                    while enter:
                        if enter == 'Q':
                            break
                        elif enter == '8':
                            B2.Pour(B1)
                            count+=1
                            break
                        elif enter == '3':
                            B2.Pour(B3)
                            count+=1
                            break
                        else:
                            enter = input("您需要选择一个桶8，3，或Q退出：\n").upper()
                    print_bucket_v(B1,B2,B3)
                    if B1.now_v == 4 or B2.now_v == 4 or B3.now_v == 4:
                        print("恭喜！，你一共用了"+str(count)+"步！")
                        return True
                    break
                elif enter == '3':
                    enter = input("选择一个被注入的桶8，5，或QUIT(Q):\n").upper()
                    while enter:
                        if enter == 'Q':
                            break
                        elif enter == '8':
                            B3.Pour(B1)
                            count+=1
                            break
                        elif enter == '5':
                            B3.Pour(B2)
                            count+=1
                            break
                        else:
                            enter = input("您需要选择一个桶8，5，或Q退出：\n").upper()
                    print_bucket_v(B1,B2,B3)
                    if B1.now_v == 4 or B2.now_v == 4 or B3.now_v == 4:
                        print("恭喜！，你一共用了"+str(count)+"步！")
                        return True
                    break
                else:
                    enter = input("您需要选择一个桶8，5，3，或Q退出：\n").upper()
            continue
        elif enter == 'Q':
            print("谢谢,欢迎下次再来！")
            break


if __name__ == "__main__":
    Bucket_game()