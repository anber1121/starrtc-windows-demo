#pragma once
#include "CUserManager.h"
#include "CMeetingManager.h"
#include "CLiveProgram.h"
// CMultipleMeetingDialog 对话框
#include "CDataShowView.h"
#include "CDataControl.h"
#include "CSoundManager.h"
class CMultipleMeetingDialog : public CDialogEx, public IMeetingManagerListener, public IChatroomGetListListener, public CLocalDataControl, public CPicControlCallback, public ISoundCallback
{
	DECLARE_DYNAMIC(CMultipleMeetingDialog)

public:
	CMultipleMeetingDialog(CUserManager* pUserManager, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMultipleMeetingDialog();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MULTIPLE_MEETING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	/**
	 * 查询聊天室列表回调
	 */
	virtual int chatroomQueryAllListOK(list<ChatroomInfo>& listData);
	/**
	 * 聊天室成员数变化
	 * @param number
	 */
	virtual void onMembersUpdated(int number);

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfKicked();

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfMuted(int seconds);

	/**
	 * 聊天室已关闭
	 */
	virtual void onClosed();

	/**
	 * 收到消息
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage);

	/**
	 * 收到私信消息
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage);


	virtual int uploaderAdd(char* upUserId, int upId);
	virtual int uploaderRemove(char* upUserId, int upId);
	virtual int getRealtimeData(int upId, uint8_t* data, int len);
	virtual int getVideoRaw(int upId, int w, int h, uint8_t* videoData, int videoDataLen);

	//src
	virtual int deleteChannel(char* channelId);
	virtual int stopOK();
	virtual int srcError(char* errString);
public:
	virtual void addUpId();
	virtual void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	virtual int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	virtual void drawPic(YUV_TYPE type, int w, int h, uint8_t* videoData, int videoDataLen);

public:
	virtual void liveExit(void* pParam);
	virtual void changeStreamConfig(void* pParam, int upid);
	virtual void closeCurrentLive(void* pParam);
	virtual void startFaceFeature(void* pParam);
	virtual void stopFaceFeature(void* pParam);
public:
	virtual BOOL OnInitDialog();
	void getMeetingList();
	afx_msg void OnNMClickListcontrolMeetingList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonMeetingListbrush();
	afx_msg void OnBnClickedButtonJoinMeeting();
public:
	virtual void getLocalSoundData(char* pData, int nLength);
	virtual void querySoundData(char** pData, int* nLength);
private:
	CUserManager* m_pUserManager;
	CMeetingManager* m_pMeetingManager;
	CSoundManager* m_pSoundManager;
	CDataShowView* m_pDataShowView;
	CListCtrl m_MeetingList;
	CLiveProgram* m_pCurrentProgram;
	int m_nUpId;
public:
	CStatic m_ShowArea;
	afx_msg void OnBnClickedButtonCreateMeeting();
};
