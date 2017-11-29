#ifndef DATAHELPER_H
#define DATAHELPER_H

    /*
    *  @brief   生成一个精度为0.01的随机数
    *  @param   lowerLimit为随机数的下限
    *           upperLimit为随机数的上限
    *  @return  指定范围内的有效精度为0.01的随机数
    */
    #define RANDOM_NUM(lowerLimit,upperLimit)\
    ((rand()%(int)((upperLimit - lowerLimit)*100)+lowerLimit)/100)


#endif // DATAHELPER_H
