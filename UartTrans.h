/***********************************************************************
 * Module:  UartTrans.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:14:02
 * Purpose: Declaration of the class UartTrans
 * Comment: 串口操作类
 ***********************************************************************/

#if !defined(__Veg_UartTrans_h)
#define __Veg_UartTrans_h

class UartTrans
{
public:
   /* 打开串口 */
   int UartOpen(int UartNo, int baudRate, std::string errStr);
   /* 串口发送 */
   int UartSend(int buf, int len, std::string errStr);
   /* 串口接收 */
   int UartRecevie(int buf, int len, std::string errStr);
   /* 关闭串口 */
   int UartColse(std::string errStr);

protected:
private:

};

#endif