// HelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TextEditor.h"
#include "HelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg dialog


CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDlg)
	//}}AFX_DATA_INIT
}


void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDlg)
	DDX_Control(pDX, IDC_HELPFILE, m_HelpText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialog)
	//{{AFX_MSG_MAP(CHelpDlg)
	//}}AFX_MSG_MAP
	ON_STN_CLICKED(IDC_HelpBackground, &CHelpDlg::OnStnClickedHelpbackground)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg message handlers

BOOL CHelpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//���ð�������
	CString str = "һ.�����ܼ��\r\n";
	str += "     1.��������һ�������������ĵ��Ļ�\r\n";
	str += "        �����ı��༭����֧�ֲ鿴��༭��\r\n";
	str += "        ����.txt���ļ�������֧�ֵ��ļ���\r\n";
	str += "        ����cpp��h��c��html��xml�����½�\r\n";
	str += "        ��txt����˵����\r\n";
	str += "     2.���������ռ��±�������ӹ�����\r\n";
	str += "        ,���ڲ�����\r\n";
	str += "     3.������֧���ַ�������ͳ�ơ����ҡ�\r\n";
    str += "        �滻�Լ����û�ָ���ַ�����ͳ�ƣ�\r\n";
    str += "     4.������֧���������ù��ܣ��û��ɶ�\r\n";
	str += "        ���塢���μ��ֵĴ�С�������ã�\r\n";
    str += "     5.ͳ�ƹ���˵�����ո���Ϊ���пո���\r\n";
	str += "        ����Ӣ�Ŀո���ͬ����Ӣ���ַ���ֻ\r\n";
	str += "        ͳ��Ӣ����ĸ������������Ǳ���\r\n";
	str += "        �ţ��������ַ����������ֺ�ȫ�Ǳ�\r\n";
	str += "        ����ţ������ַ�������Ӣ�ġ�����\r\n";
	str += "        ��ȫ�ǺͰ���ַ����Լ��ո�����\r\n";
	str += "\r\n";

	str += "��.����ʹ�ü��\r\n";
    str += "     1.��������˵��������������༭��\r\n";
    str += "        �˵������������ɽ��и��ֲ�������\r\n";
	str += "        ����ɽ����ı��༭��\r\n";
    str += "     2.�˵�����������������Ӧ�Ŀ�ݼ�Ϊ\r\n";
    str += "            �½���Ctrl+N          �򿪣�Ctrl+O\r\n";
    str += "            ���棺Ctrl+S          ������Ctrl+Z\r\n";
    str += "            ������Ctrl+Y          ȫѡ��Ctrl+A\r\n";
    str += "            ���У�Ctrl+X          ���ƣ�Ctrl+C\r\n";
    str += "            ճ����Ctrl+V   �����滻��Ctrl+F  \r\n";
    str += "            ���壺Alt+F          ������Ctrl+H\r\n";
    str += "         ���������ں������˵����\r\n";
	str += "\r\n";

	str += "��.������Ҫ����\r\n";
    str += "     1.�ļ���\r\n";
    str += "     ���½�������һƪ�հ��ĵ����ӡ���\r\n";
	str += "         ���������ļ������˵����д���\r\n";
	str += "     �ڴ򿪣����ı���.txt���ļ����ӡ�\r\n";
	str += "         �����������ļ������˵����д�\r\n";
	str += "         �������ı���.txt���ļ��������\r\n";
    str += "         ����򿪻�Ӧ�ó���TextEditor.exe\r\n";
	str += "         ͼ���ϴ򿪣����Ҽ������ı��ļ���\r\n";
	str += "         �ڡ��򿪷�ʽ����ѡ�񱾳����\r\n";	      
	str += "     �۱��棺�����ĵ����ӡ�����������\r\n";
	str += "         ���ļ������˵����д�\r\n";
	str += "     �����Ϊ�������ļ��������ڲ�ͬλ\r\n";
    str += "         �û��Բ�ͬ�ļ��������ĵ����ӡ���\r\n";
	str += "         ���������ļ������˵��������\r\n";
	str += "     2.�༭��\r\n";
	str += "     �ٳ���������ǰһ�������еĲ�����\r\n";
	str += "         �ӡ��༭�����˵������Ҽ��˵�\r\n";
	str += "         ���г�����֧�ֶ༶����\r\n";
	str += "     ������������ǰһ���������Ĳ�������\r\n";
	str += "         ���༭�����˵������Ҽ��˵�����\r\n";
	str += "         ������֧�ֶ༶����\r\n";
	str += "     ��ɾ����ɾ����ǰѡ���ַ���������\r\n";
	str += "         �ӡ��༭�����˵������Ҽ��˵�\r\n";
	str += "         ����ɾ��\r\n";
	str += "     �ܼ��У����Ʋ�ɾ��ѡ���ַ�������\r\n";
	str += "         ���ӡ��༭�����˵������Ҽ���\r\n";
	str += "         �����м���\r\n";
	str += "     �ݸ��ƣ�����ѡ���ַ����������ӡ���\r\n";
	str += "         �������˵������Ҽ��˵����и���\r\n";
	str += "     ��ճ������ճ�����ݽ���ճ�����ӡ���\r\n";
	str += "         �������˵������Ҽ��˵�����ճ��\r\n";
	str += "     ��ȫѡ�����ı��༭�����ı�ȫ��ѡ��\r\n";
	str += "         ���ӡ��༭�����˵������Ҽ��˵�\r\n";
	str += "         ����ȫѡ\r\n";
    str += "     3.Ӧ�ã�\r\n";
	str += "     �ٲ���/�滻������������ݣ����滻\r\n";
	str += "         ���ݣ����ɴӹ��λ��������ң���\r\n";
	str += "         �滻����Ӧ���ݣ�Ҳ��һ����ȫ����\r\n";
	str += "         ������Ӧ���ݣ��ӡ�����������Ӧ\r\n";
	str += "         �������˵�����ִ��\r\n";
	str += "     ���������ã��������塢���μ��ֵĴ�\r\n";
	str += "         С���ӡ�����������Ӧ�������˵�\r\n";
	str += "         ������������\r\n";
	str += "     ��ͳ��������ͳ�������ַ�����������\r\n";
    str += "         ������Ӣ���ַ����������ַ����Ϳ�\r\n";
	str += "         �������ӡ�����������Ӧ��������\r\n";
	str += "         ����������\r\n";
	str += "     �ܹ���ע�᣺��ע������TextEditor�ļ���\r\n";
	str += "         �����ı��ı���.txt���ļ�ͼ�꣬��\r\n";
	str += "         ʹ�ı���.txt���ļ��ɵ����Ҽ���ѡ\r\n";
	str += "         ���ñ������(���ֹ���������ע\r\n";
	str += "         ��������Ч)\r\n";
	str += "     �ݻ�ԭע�᣺ȡ��ע�ᣬ�ı���.txt��\r\n";
	str += "         �ļ���ԭΪĬ��ͼ�꣬�����Ҽ���\r\n";
	str += "         (���ֹ���������ע��������Ч)\r\n";
	str += "     4.������\r\n";
	str += "     �ٲ鿴��������ʾ��������ĵ�������\r\n";
	str += "         �����ܡ�ʹ�á���Ҫ˵���ȸ�����\r\n";
	str += "         Ϣ���ӡ����������򡰰��������˵�\r\n";
	str += "         ��������\r\n";
	str += "     �ڹ���TextEditor����ʾ���ڱ������\r\n";
	str += "         ��Ϣ���ӡ����������˵���������\r\n";

	m_HelpText.SetWindowText(str);									//��ʾ��������
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CHelpDlg::OnStnClickedHelpbackground()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
