/***********************************************************************
 * Module:  Camera.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:01:38
 * Purpose: Declaration of the class Camera
 * Comment: ����ͷ������
 ***********************************************************************/

#if !defined(__Veg_Camera_h)
#define __Veg_Camera_h

class Camera
{
public:
   /* ������ͷ */
   int OpenCamera(std::string errStr);
   /* ��������ͷ */
   int SetCamera(int format, int width, int height, std::string errStr);
   /* ��ȡһ֡ͼ�����bufΪNULL���򷵻�ͼ������ռ�Ĵ�С weight*height */
   int GetFrame(int buf, int weight, int length, std::string errStr);
   /* �ر�����ͷ */
   int CloseCamera(std::string errStr);

protected:
private:

};

#endif