/***********************************************************************
 * Module:  RS485Operater.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:40:23
 * Purpose: Declaration of the class RS485Operater
 * Comment: RS485������
 ***********************************************************************/

#if !defined(__Veg_RS485Operater_h)
#define __Veg_RS485Operater_h

class RS485Operater
{
public:
   /* ��ָ����ַ�������� */
   int Send(int Addr, int buf, int len, int errStr);
   /* ��ʼ�� */
   int Init(int Addr, std::string errStr);
   /* �������� */
   int Receive(int Addr, int buf, int len, std::string errStr);
   /* �ر�485 */
   int Close(std::string errStr);

protected:
private:

};

#endif