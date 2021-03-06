#ifndef __UUPACKET_FACTORY_MANAGER_H__ 
#define __UUPACKET_FACTORY_MANAGER_H__

#include "UUPacket.h"
#include "UUPacketEXT.h"
#include "UUPacketFactory.h"

#define PACKET_HEARTBEAT  1
#define PACKET_GENERAL  2

#define PACKET_CG_HEARTBEAT  1

#define PACKET_CG_STUDY_FORMATION  16
#define PACKET_CG_LEVEL_UP_FORMATION  17
#define PACKET_CG_FORMATION_LIST  12
#define PACKET_CG_GENERAL_LIST  5
#define PACKET_CG_SELECT_FORMATION  18
#define PACKET_CG_FIX_FORMATION  19
#define PACKET_CG_MODIFY_FORMATION  13

#define PACKET_CG_STARRING_ATTRIBUTE  2
#define PACKET_CG_CULTURE  6
#define PACKET_CG_TELENT_LIST  9
#define PACKET_CG_LIGHT_UP_TELENT  8
#define PACKET_CG_SOUL_BEAD_LIST  11
#define PACKET_CG_SOUL_BEAD_EQUIP_LIST  7
#define PACKET_CG_PUT_ON_SOUL_BEAD  20
#define PACKET_CG_TAKE_OFF_SOUL_BEAD  21
#define PACKET_CG_SWAP_SOUL_BEAD  25

#define PACKET_MAX 65535

class UUPacketFactoryManager 
{
public :
	UUPacketFactoryManager( ) ;

	~UUPacketFactoryManager( ) ;

	void				AddFactory( UUPacketFactory* pFactory ) ;

	// 初始化接口
	void				Init( ) ;

	// 根据消息类型从内存里分配消息实体数据（不允许多线程同时调用）
	UUPacketEXT*		CreatePacket( unsigned short packetID ) ;
	
	//删除消息实体（允许多线程同时调用）
	void				RemovePacket( UUPacketEXT* pPacket ) ;

	UUPacketFactory **	m_Factories ;

	unsigned short   	m_Size ;

	unsigned int*		m_pPacketAllocCount ;
};

extern UUPacketFactoryManager* g_pPacketFactoryManager;

#endif