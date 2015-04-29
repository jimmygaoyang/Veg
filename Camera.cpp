/***********************************************************************
 * Module:  Camera.cpp
 * Author:  Thinkpad
 * Modified: 2015-04-29 14:01:38
 * Purpose: Implementation of the class Camera
 * Comment: 摄像头操作类
 ***********************************************************************/

#include "Camera.h"

////////////////////////////////////////////////////////////////////////
// Name:       Camera::OpenCamera(std::string errStr)
// Purpose:    Implementation of Camera::OpenCamera()
// Comment:    打开摄像头
// Parameters:
// - errStr
// Return:     int
////////////////////////////////////////////////////////////////////////

int Camera::OpenCamera(std::string errStr)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Camera::SetCamera(int format, int width, int height, std::string errStr)
// Purpose:    Implementation of Camera::SetCamera()
// Comment:    设置摄像头
// Parameters:
// - format
// - width
// - height
// - errStr
// Return:     int
////////////////////////////////////////////////////////////////////////

int Camera::SetCamera(int format, int width, int height, std::string errStr)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Camera::GetFrame(int buf, int weight, int length, std::string errStr)
// Purpose:    Implementation of Camera::GetFrame()
// Comment:    获取一帧图像，如果buf为NULL，则返回图像所需空间的大小 weight*height
// Parameters:
// - buf
// - weight
// - length
// - errStr
// Return:     int
////////////////////////////////////////////////////////////////////////

int Camera::GetFrame(int buf, int weight, int length, std::string errStr)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Camera::CloseCamera(std::string errStr)
// Purpose:    Implementation of Camera::CloseCamera()
// Comment:    关闭摄像头
// Parameters:
// - errStr
// Return:     int
////////////////////////////////////////////////////////////////////////

int Camera::CloseCamera(std::string errStr)
{
   // TODO : implement
}