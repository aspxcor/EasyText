#include "stdafx.h"
#include "TextEditorDlg.h"
#include "CUndo.h"


CUndo::CUndo(){
	m_undolevels = 10;
}

CUndo::~CUndo() {
	POSITION pos = m_undolist.GetHeadPosition();
	CMemFile* nextFile = NULL;
	while (pos) {
		nextFile = (CMemFile*)m_redolist.GetNext(pos);
		delete nextFile;
	}
	m_undolist.RemoveAll();
	ClearRedoList();
}

void CUndo::Load(CMemFile* file)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	DeleteContents();
	file->SeekToBegin();
	CArchive ar(file, CArchive::load);	//CArchieve������Ϊload
	CDocument::Serialize(ar);
	ar.Close();
}


void CUndo::AddUndo(CMemFile* file)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (m_undolist.GetCount() > m_undolevels) {
		CMemFile* pFile = (CMemFile*)m_undolist.RemoveTail();
		delete pFile;
	}
	m_undolist.AddHead(file);
}



void CUndo::ClearRedoList()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	POSITION pos = m_redolist.GetHeadPosition();	//posΪ����ͷ��¼
	CMemFile* nextFile = NULL;
	while (pos) {
		nextFile = (CMemFile*)m_redolist.GetNext(pos);
		delete nextFile;
	}
	m_redolist.RemoveAll();
}


void CUndo::CheckPoint()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	CMemFile* file = new CMemFile(50000);
	char write[50000];
	CString strText = "";
	m_Edit.GetWindowText(strText);  //��ȡ�༭���е�����
	strcpy(write, strText);
	file->Write(write,strText.GetLength());
	AddUndo(file);
	ClearRedoList();
}


void CUndo::Undo()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (m_undolist.GetCount() > 1) {
		CMemFile* pFile = (CMemFile*)m_undolist.GetHead();
		m_undolist.RemoveHead();
		m_redolist.AddHead(pFile);
		pFile = (CMemFile*)m_undolist.GetHead();
		Load(pFile);
	}
}



void CUndo::Redo()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (m_redolist.GetCount() > 0) {
		CMemFile* pFile = (CMemFile*)m_redolist.GetHead();
		m_redolist.RemoveHead();
		AddUndo(pFile);
		Load(pFile);
	}
}
