/***********************************************************************
 * Module:  Camera.h
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:01:38
 * Purpose: Declaration of the class Camera
 * Comment: 摄像头操作类
 ***********************************************************************/

#if !defined(__Veg_Camera_h)
#define __Veg_Camera_h

class Camera
{
public:
   /* 打开摄像头 */
   int OpenCamera(std::string errStr);
   /* 设置摄像头 */
   int SetCamera(int format, int width, int height, std::string errStr);
   /* 获取一帧图像，如果buf为NULL，则返回图像所需空间的大小 weight*height */
   int GetFrame(int buf, int weight, int length, std::string errStr);
   /* 关闭摄像头 */
   int CloseCamera(std::string errStr);

protected:
private:

};

#endif