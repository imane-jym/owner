#ifndef __GM_COMMAND_EXT_H__
#define __GM_COMMAND_EXT_H__

#include "GmCommand.h"
#include "ConfigData.h"
#include "CommonType.h"

class CancelCommand : public GmCommand
{
public:
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();

private:
	uint32	m_dwGmAutoId;
};

class ReloadConfigCommand : public GmCommand
{
public:
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();
private:
	std::string m_strTable;
};

class SetRoleAuth: public GmCommand
{
public:
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();
private:
	uint32 gm;
	uint32 limit;
};

class SetServer: public GmCommand
{
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();
private:
	uint8_t m_areaid;
	uint8_t m_status;
	uint8_t m_new;
	uint8_t m_canlogin;
	std::string m_name;
	std::string m_domain;
	std::string m_resurl;
};

class ForceCancel: public GmCommand
{
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();
private:
	uint32_t m_activeIndex;

};

class WhiteList: public GmCommand
{
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();
private:
	std::vector<uint32_t> m_vecUserid;

};

class NoticeCtrl: public GmCommand
{
	virtual bool Validate();
	virtual bool Trigger();
	virtual bool Complete();
private:
	std::string m_strContent;
	uint8_t m_byChatType;
	uint8_t m_byChoose;
};
#endif
