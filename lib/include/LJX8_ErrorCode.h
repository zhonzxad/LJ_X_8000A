//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
/** @file
@brief	LJX8_ErrorCode Header
*/

#define LJX8IF_RC_OK						0x0000	// 正常终止
#define LJX8IF_RC_ERR_OPEN					0x1000	// 打开通讯路径失败
#define LJX8IF_RC_ERR_NOT_OPEN				0x1001	// 通讯路径未建立
#define LJX8IF_RC_ERR_SEND					0x1002	// 发送命令失败.
#define LJX8IF_RC_ERR_RECEIVE				0x1003	// 未能收到正确应答.
#define LJX8IF_RC_ERR_TIMEOUT				0x1004	// 等待响应期间发生超时
#define LJX8IF_RC_ERR_NOMEMORY				0x1005	// 分配内存失败
#define LJX8IF_RC_ERR_PARAMETER				0x1006	// 传递了无效的参数
#define LJX8IF_RC_ERR_RECV_FMT				0x1007	// 收到的响应数据无效

#define LJX8IF_RC_ERR_HISPEED_NO_DEVICE		0x1009	// 无法执行高速通信初始化
#define LJX8IF_RC_ERR_HISPEED_OPEN_YET		0x100A	// 高速通讯已初始化
#define LJX8IF_RC_ERR_HISPEED_RECV_YET		0x100B	// 高速通信中已经发生错误（用于高速通信）
#define LJX8IF_RC_ERR_BUFFER_SHORT			0x100C	// 作为参数传递的缓冲区大小不足 
