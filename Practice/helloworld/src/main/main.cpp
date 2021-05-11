//  main.cpp
#include "helloworld.h"
#include "adapter_gflags.h"
#include <stdio.h>
#include <stdlib.h>
 #include<time.h>
 #include <string>
 #include <vector>

static int g_arr[2] = {0,1};

const std::string g_str("1:2:3");


//字符串分割算法
static void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

int getVehicleTypeRandom(const std::string &strVechicleProb, const std::string &strSplit)
{
    std::vector<std::string> vecTypeProb;
    SplitString(strVechicleProb, vecTypeProb, strSplit);
    int iFirstType = 0;
    int iSecondType = 0;
    int iThirdType = 0;
    // printf("vecTypeProb.size =%d\n", vecTypeProb.size());
    if(3 == vecTypeProb.size())
    {
        iFirstType = atoi(vecTypeProb[0].data());
        iSecondType = atoi(vecTypeProb[1].data());
        iThirdType = atoi(vecTypeProb[2].data());
    }
    else
    {
        iFirstType = 1;
        iSecondType = 0;
        iThirdType = 0;
    }
    // printf("iFirstType=%d, iSecondType=%d, iThirdType=%d\n", iFirstType, iSecondType, iThirdType);
    int iTotalNum = iFirstType + iSecondType + iThirdType;
    int iType = rand() % iTotalNum; //三型车的总比例数
    int iIntelligence = 0;
    if(iType  < iFirstType)
    {
        iIntelligence = 0;
    }
    else if( iType < (iSecondType + iFirstType))
    {
        iIntelligence = 1;
    }
    else
    {
        iIntelligence = 2;
    }
    return iIntelligence;
}

//类中的成员函数声明顺序
class ADemo{
public:
    void init(){
        printFun();
    }
    void printFun(){
        printf("ADemo printFun is called!\n");
    }
};




int main(int argc, char * argv[])
{
    ADemo aDemo;
    aDemo.init();
    return 0;


    std::string strModel("MeituanBatteryCar-MeituanDeliveryBoy");
    // size_t pos1 = 0;
    auto pos2 = strModel.find_first_of("-");
    std::string strModelSplit = strModel.substr(0, pos2);
    printf("strModelSplit = %s\n", strModelSplit.data());

    return 0;

    std::string strTmp = FLAGS_vehicle_prob;
    printf("FLAGS_vehicle_prob=%s\n", strTmp.data());
    srand((unsigned(time(NULL))));
    
    // std::vector<std::string> vecStrProb;
    // for(int i = 0; i < argc; ++i)
    // {
    //     printf("arvg[%d] = %s\n", i, argv[i]);
    // }

    // SplitString(argv[1], vecStrProb, argv[2]);
    // for( const auto &prob : vecStrProb)
    // {
    //     printf(" %s", prob.data());
    // }
    // printf("\n");

    // return 0;

    if(4 != argc)
    {
        printf("the input command argc should 2\n");
        return -1;
    }
    int num = atoi(argv[1]);

#if 0
    printf("the generate arr is : \n");
    int temp = 0;
    int icount = 0;
    // struct tm *p;
    for(int i = 0; i < num; ++i)
    {
        if(((i %10) == 0) && (0 != i))
        {
            printf("\n");
        }
        temp = g_arr[rand()%2];
        printf(" %d", rand());
        // printf(" %d", temp);
        if(0 == temp)
        {
            ++icount;
        }
        // printf("Argument %d is %s\n", i, argv[i]);
    }
    printf("\n");
    printf("the arr num of 0 :%d, the num of 1: %d\n", icount, (num - icount));
#endif
    // helloworld obt;
    // obt.outputWord();
    // generateRand(num);
    int iFirstCount = 0;
    int iSecondCount = 0;
    int iThirdCount = 0;
    int iType = 0;
    for( int i = 0; i < num; ++i)
    {
        iType = getVehicleTypeRandom(argv[2], argv[3]);
        switch (iType)
        {
        case 0:
            ++iFirstCount;
            break;
        case 1:
            ++iSecondCount;
            break;
        case 2:
            ++iThirdCount;
            break;
        default:
            break;
        }
    }
    printf("iFirstCount=%d, iSecondCount=%d, iThirdCount=%d\n", iFirstCount, iSecondCount, iThirdCount);
    return 0;
}

