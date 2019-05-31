// EditWindow.cpp : implementation file

#include "stdafx.h"
#include "TextEditor.h"
#include "EditWindow.h"
#include "TextEditorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// EditWindow

EditWindow::EditWindow()
{
	//m_Bitmap.LoadBitmap(IDB_EditBack);
}

EditWindow::~EditWindow()
{
}


BEGIN_MESSAGE_MAP(EditWindow, CEdit)
	//{{AFX_MSG_MAP(EditWindow)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_VSCROLL()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_DROPFILES()
	ON_WM_CTLCOLOR()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// EditWindow message handlers

/*BOOL EditWindow::OnEraseBkgnd(CDC* pDC) 
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);												//�����ڴ��豸������
	memDC.SelectObject(&m_Bitmap);												//��λͼѡ���豸������
	BITMAP m_Bmp;																//����λͼ�ؼ�
	m_Bitmap.GetBitmap(&m_Bmp);													//���λͼ��Ϣ
	int x = m_Bmp.bmWidth;														//��ȡͼƬ���
	int y = m_Bmp.bmHeight;														//��ȡͼƬ�߶�
	CRect rect;																	//���������������
	GetClientRect(rect);														//��ȡ�༭����С���ο�
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY);		//��չ����ͼƬ
	memDC.DeleteDC();															//�ͷ��ڴ��豸������
	return TRUE;
	
	//return CEdit::OnEraseBkgnd(pDC);
}
*/

void EditWindow::OnChange() 
{
	// send this notification unless you override the CEdit::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	Invalidate();																//ˢ���û�����
	
}

HBRUSH EditWindow::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetBkMode(TRANSPARENT);												//�������ֱ���͸��
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}


void EditWindow::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar * pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CEdit::OnVScroll(nSBCode, nPos, pScrollBar);								//�жϹ������Ƿ񻬶�
	Invalidate();																//ˢ���û�����
}

void EditWindow::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	int n1,n2;
	n1 = GetScrollPos (SB_VERT);
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
	n2 = GetScrollPos (SB_VERT);
	if (n1 != n2)																//�жϹ������Ƿ񻬶�
	{
		Invalidate();															//ˢ���û�����
	}
}

BOOL EditWindow::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	BOOL editS = CEdit::OnMouseWheel(nFlags, zDelta, pt);

	Invalidate();																//ˢ���û�����
	
	return editS;
}

//*****************************//
//�����ļ��Ĵ�����(�༭��)   //
//*****************************//
void EditWindow::OnDropFiles(HDROP hDropInfo) 
{
	CWnd* pWnd = AfxGetApp()->GetMainWnd();											//��������ھ��
	CTextEditorDlg * pDlg;
	pDlg=(CTextEditorDlg *) pWnd;															//���ָ�������ڵ�ָ��
	EditWindow * m_EditPtr = & (pDlg->m_Edit);										//����ָ��ָ��������m_Edit�ؼ�

	char *lpszFileName=new char[512]; 
	int nFileCount,i; nFileCount=::DragQueryFile (hDropInfo,0xFFFFFFFF,NULL,512);	//��¼������ļ�				
	
	for (i=0;i<nFileCount;i++)
	{ 
		UINT nChars=::DragQueryFile (hDropInfo,i,&lpszFileName[0],512); 
		CString str(&lpszFileName[0],nChars);										//����ļ�·��


		//��ǰ�������ı��ĵĴ���
		pDlg->isModified = m_EditPtr->GetModify();									//��ȡ�ı��޸ı��
	
		CString string;
		m_EditPtr->GetWindowText(string);
		if (pDlg->isNew && string.IsEmpty())										//�����½��ı����ı�����������
		{
			pDlg->isNew = FALSE;
		}

		else if(pDlg->isModified)													//����ı��ѱ��޸ģ����������
		{
			int Choice = MessageBox("��ǰ�ı��ѱ��޸ģ��뱣����","ϵͳ��ʾ",
			MB_YESNO|MB_ICONQUESTION);												//������Ϣ�Ի���ѯ��
			if(Choice==IDYES)														//ѡ���ǡ�
			{
				pDlg->OnMenuSave();													//���ñ��溯�������ļ�
			}
		}

		CString strPath,strText="";
		strPath = str;
	
		pDlg->SavePath = str;

		int n = pDlg->SavePath.ReverseFind('.');   
		CString stl = (pDlg->SavePath).Right((pDlg->SavePath).GetLength() - n - 1);
		if (stl == "txt" || stl == "TXT" || stl == "c" || stl == "C" || stl == "cpp" || stl == "CPP"
			|| stl == "h" || stl == "H" || stl == "xml" || stl == "XML" || stl == "html" || stl == "HTML")
		{
			CFile file(str,CFile::modeReadWrite);										//�Զ���д��ʽ���ļ�		
		
			//�����
			m_EditPtr->SetSel(0, -1);													//ȫ��ѡ���ı�����
			m_EditPtr->Clear();															//�������ı�ɾ��

			char read[50000];
			file.Read(read,50000);														//��ȡ�ļ�����
			for(unsigned i=0;i<file.GetLength();i++)
			{
				strText += read[i];														//���ļ����ݸ�ֵ��CString����
			}		
			file.Close();																//�ر��ļ�
			m_EditPtr->SetWindowText(strText);

			pDlg->isNew = FALSE;														//���Ϊ���ı�
			m_EditPtr->SetModify(FALSE);												//�ı��޸ı����Ϊ�޸�
		}
		else
		{
			MessageBox ("��֧�ֵ��ļ����ͣ�","�򿪴���");
		}
	} 
	::DragFinish (hDropInfo);															//�ͷ��ڴ� 
	i=0;
	delete []lpszFileName; 
}

//*****************************//
//   ��������˶����й���Ӧ     //
//*****************************//

void EditWindow::OnMouseMove(UINT nFlags, CPoint point) 
{
	int n1,n2;
	n1 = GetScrollPos (SB_VERT);
	CEdit::OnMouseMove(nFlags, point);
	n2 = GetScrollPos (SB_VERT);
	if (n1 != n2)																//�жϹ������Ƿ񻬶�
	{
		//Invalidate();															//ˢ���û�����
		CRect rect (15,80,586,686);
		InvalidateRect(rect);													//ˢ���û�����
	}
}
