# basics-of-IOT-based-reality-combat-midterm

期中開發日誌
---
### 2018/09 課堂
*領材料
### 2018/10/04 課堂
*焊接擴充版
### 2018/10/11 課堂
*組裝車子
### 2018/10/13 晚上
*發現code的rightpin是左輪  
*測試馬達和超音波模組ok   
*車能走直線  
### 2018/10/16 晚上
*用digitalWrite and delay in function  
*開放教室 車能左轉  
*發現車會卡在迷宮的小柱子  
### 2018/10/18 
*買PP板  
*晚上開放教室 車變成只會直走  
*兩小時多想不出原因  
### 2018/10/20 下午
*在家用木板建像迷宮一小部分的跑道  
*═+∟組成╗╖╔  
### 2018/10/21 下午
*加Serial Print for distance  
*修改(簡化)if條件判斷後，車終於會判斷了  
*瘋狂調參數，車終於能接近90度左右轉以及180度迴轉  
### 2018/10/22
*黏上PP板  
### 2018/10/23
*下午畫迷宮，看出適合多次左牆法則加幾次右牆法則  
*決定一律左牆法則  
*晚上開放教室，因杜邦線卡開關，問助教得知vcc和gnd能移往左邊。  
*因實際迷宮木板材質和家裡不同，重新調參數。  
*得知之前對delay time的認知有誤  
*車能走十幾格了  
*發現車旁兩片PP板中間會卡東西，在板子之間再黏板子，在車子前半部圍成一圈。  
### 2018/10/24
9:00到10:00   
*調整code 車能走三十幾格了   
*會卡在那一圈PP板，考慮是否拆掉  
*加Serial Print in function  
15:00到18:00   
*本來打算存取兩次距離判斷是否卡住，經同學指點，接上電腦一看，發現持續3次go left或10次go表示卡住。   
*車可繞一圈走回起點，但途中會折返好幾次，不走進有些地方。  
*增加go的時間  
19:00到20:50  
*發現車子因修正(不要貼牆)而多次後退，刪或縮短backward。  
*一直轉彎不到位，瘋狂調參數。經助教指點，才發現電壓降到3V以下。  
*當下不知如何解決，明天就要考了，只好問助教明天是否開放教室。  
### 2018/10/25 早上  
9:40到12:50  
*本來想說充飽電再降壓到適合的狀態。充到3V以上就ok了。  
*車又可繞一圈了，但測時間發現太慢。  
*ena和enb改成235，參數先按其倍率倒數修改，實測後再細調。  
*突然發現會卡在詭異的地方(左右>25 && 前>3000)，緊急修改code。  
### 2018/10/25 課堂  
*期中考    
*用3.34V的電池  
*第一次用慢版跑，車子保守地前進。有及格。  
*第二次用快版跑  

謝謝家人、教授以及教導我的助教和同學  

*車子功能:  
---
前進，停止，後退，右轉，左轉  

*戰術:  
---
左牆法則  


![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/1.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/2.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/3.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/5.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/6.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/7.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/8.jpg)
![image](https://github.com/BookCatCSIE/basics-of-IOT-based-reality-combat-midterm/blob/master/photos/9.jpg)
