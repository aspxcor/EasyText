#pragma once
//#include <afxwin.h>
class CUndo : public CDocument , public CTextEditorDlg
{	public:
	CUndo();
	~CUndo();
	CObList m_undolist;
	CObList m_redolist;
	void Load(CMemFile* file);
	void AddUndo(CMemFile* file);
private:
	// ��������
	int m_undolevels;
public:
	void ClearRedoList();
	void CheckPoint();
	void Undo();
	void Redo();
};

