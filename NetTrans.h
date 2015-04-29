/***********************************************************************
 * Module:  NetTrans.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 13:49:24
 * Purpose: Declaration of the class NetTrans
 * Comment: ����ͨ���࣬�������Ӻ�̨���������ݡ��������ݡ��Ͽ�����
 ***********************************************************************/

#if !defined(__Veg_NetTrans_h)
#define __Veg_NetTrans_h

class NetTrans
{
public:
   /* ���ӷ����� */
   int NetConnect(std::string IP, std::string port, std::string errStr);
   /* �������ݵ���̨ */
   int NetSend(char buf, int len, std::string errStr);
   /* �Ӻ�̨�������ݣ��������������timeoutʱ����û�����ݴ������˳� */
   int NetRecevie(char buf, int len, int timeout, std::string errStr);
   /* �ر����� */
   int NetClose(std::string errStr);

protected:
private:

};

#endif