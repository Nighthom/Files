# real mode

>> 리얼 모드는 x86 / x64 아키텍쳐에서 부팅 직후에 실행되는 모드입니다.  
>> 오로지 16비트 명령어만 지원합니다.  

>> 리얼 모드는 보호 모드(Protected Mode)와 다르게  
>> 메모리에의 잘못된 접근을 차단할 수 없습니다. 가상 메모리 지원도  
>> 해주지 않습니다.  

>> 그리고 메모리는 1mb까지만 이용이 가능합니다.  

>> 리얼 모드로 부팅이 되면 첫번쨰 우선순위로 지정되어있는   
>> HDD, SDD, USB 등 보조기억 주변기기의 첫 섹터에서 부트 시그니쳐를 찾습니다.  
>> 일반적으로 하나의 섹터의 크기는 512Byte이고,  
>> 이 섹터의 마지막 2바이트에 (510 ~ 512) 0xAA55(리틀 엔디언에서는 55AA)라는 부트 시그니쳐가 있으면  
>> 리얼모드는 이를 부트 가능한 디스크라고 인식하고 부팅을 시도합니다.   


## 리얼 모드에서의 세그먼트 절대 주소 계산법
>> assembly ORG = 0
>> 
>> SS : 0x00
>> DS : 0x7c0
>> ES : 0x7c0


>> 만약 DS에 속하고, 오프셋이 0x10인 Data의 경우,  
>> 1. x = 세그먼트 주소 * 16(0x10)
>> 2. x += offset
>> 의 과정을 거쳐  
>> 0x7c00 + 0x10 = 0x7c10 이 됩니다.    

## FAT 포맷에서의 부트로더 
>> FAT 포맷에서는 첫 32바이트에 BPB라는것을 집어넣습니다.  
>> 만약, 32바이트 안에 데이터를 넣도록 프로그래밍한다면,  
>> 임의의 값이 Set되고, 예상치 못한 결과를 불러올 수 있어요.  
>> 즉, NULL Padding을 삽입해서 Data Sector 첫 32byte에는   
>> 어떠한 Data가 오지 않도록 해 주어야 합니다.  
