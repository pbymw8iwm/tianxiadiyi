
/**	GIDataBase.h
 */

#pragma once


#include "BaseType.h"


/// 引用WXSJ_DBC.h中的公用类
namespace DBC
{
	class DBCFile;
};

//===================================================
/// 客户端用内存数据库(DataBaseClient)

/// 内存数据库
class tDataBase
{
public:

	/// 字段数据类型
	enum DBC_FIELD_TYPE
	{
		T_INT		= 0,	// 整数
		T_FLOAT		= 1,	// 浮点数
		T_STRING	= 2,	// 字符串
	};

	// 数据段
	union DBC_FIELD
	{
		FLOAT		fValue;
		INT			iValue;
		const CHAR*	pString;	// Just for runtime!

		// Construct
		DBC_FIELD() {}
		DBC_FIELD(INT value) { iValue = value; }
		DBC_FIELD(FLOAT value) { fValue = value; }
		DBC_FIELD(const CHAR* value) { pString = value; }
	};

public:

	// 按照索引查找
	virtual const DBC_FIELD* Search_Index_EQU(INT iIndexValue) const = 0;
	// 按照行
	virtual const DBC_FIELD* Search_LineNum_EQU(INT iLineNum) const = 0;
	// 查找某列等于指定值的第一行
	virtual const DBC_FIELD* Search_First_Column_Equ(INT nColumnNum, const DBC_FIELD& value) const = 0;
	//查找某列等于指定值的第nRow行
	virtual const DBC_FIELD* Search_Column_Equ(INT nRow,INT nColumnNum, const DBC_FIELD& value) const = 0;

public:

	virtual	const DBC::DBCFile* GetDBCFile( VOID ) const = 0;
	// 取得ID
	virtual INT GetID(VOID) const = 0;
	// 取得列数
	virtual UINT GetFieldsNum(VOID) const = 0;
	// 取得记录的条数
	virtual UINT GetRecordsNum(VOID) const = 0;
};	// class

/** 数据库管理器
 */
class tDataBaseSystem
{
public:
	/** 打开系统中所有数据库 */
	virtual VOID OpenAllDataBase(VOID) = 0;
	/** 关闭系统中所有数据库 */
	virtual VOID CloseAllDataBase(VOID) = 0;
	/** 得到一个已近打开的数据库，返回数据库指针 */
	virtual const tDataBase* GetDataBase(INT idDataBase) const = 0;
};	// class