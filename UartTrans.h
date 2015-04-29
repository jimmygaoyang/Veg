/***********************************************************************
 * Module:  UartTrans.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:14:02
 * Purpose: Declaration of the class UartTrans
 * Comment: ���ڲ�����
 ***********************************************************************/

#if !defined(__Veg_UartTrans_h)
#define __Veg_UartTrans_h

class UartTrans
{
public:
   /* �򿪴��� */
   int UartOpen(int UartNo, int baudRate, std::string errStr);
   /* ���ڷ��� */
   int UartSend(int buf, int len, std::string errStr);
   /* ���ڽ��� */
   int UartRecevie(int buf, int len, std::string errStr);
   /* �رմ��� */
   int UartColse(std::string errStr);

protected:
private:

};

#endif