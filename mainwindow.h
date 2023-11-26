#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlDatabase>
#include <QTableView>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_Back_1_clicked();

    void on_Reg_sts_clicked();

    void on_pushButton_3_clicked();

    void on_back_2_clicked();

    void on_Reg_con_sts_clicked();

    void on_Login_sts_clicked();

    void on_back_cr_clicked();

    void on_back_3_clicked();

    void on_back_4_clicked();

    void on_Reg_con_sts_2_clicked();

    void on_back_6_clicked();

    void on_hlp_back_clicked();

    void on_back_sup_clicked();

    void on_back_SUP_clicked();

    void on_back_5_clicked();

    void on_Reg_con_sts_3_clicked();

    void on_Back_2_clicked();

    void on_Reg_sts_2_clicked();

    void on_Back_3_clicked();

    void on_Reg_sts_3_clicked();

    void on_con_pass_st_cursorPositionChanged(int arg1, int arg2);

    void on_pass_st_cursorPositionChanged(int arg1, int arg2);

    void on_Login_sts_3_clicked();

    void on_Login_sts_2_clicked();

    void on_logic_cr_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_back_sup_2_clicked();

    void on_pushButton_4_clicked();

    void on_back_sup_3_clicked();

    void on_pushButton_5_clicked();

    void on_login_SUP_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_27_clicked();

    void on_back_sup_7_clicked();

    void on_back_sup_6_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_88_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_93_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_20_clicked();

    void on_ok_sup_2_clicked();

    void on_bus_col_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_81_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_96_clicked();

    void on_pushButton_94_clicked();

    void on_pushButton_82_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_103_clicked();

    void on_Back_4_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_30_clicked();

    void on_ok_sup_clicked();

    void on_pushButton_41_clicked();

    void on_ok_sup_3_clicked();

    void on_Login_sts_4_clicked();

    void on_reg_con_dr_clicked();

    void on_pushButton_100_clicked();

    void on_label_14_linkActivated(const QString &link);

    void on_label_5_linkActivated(const QString &link);

    void on_pushButton_104_clicked();

    void on_pushButton_97_clicked();

    void on_pushButton_102_clicked();

    void on_bus_save_clicked();

    void on_con_dr_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_106_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_98_clicked();

    void on_ok_sup_7_clicked();

    void on_ok_sup_8_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_44_clicked();

    void on_hlp_save_clicked();

    void on_back_sup_8_clicked();

    void on_ok_sup_9_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_112_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_48_clicked();

    void on_back_cr_2_clicked();

    void on_logic_cr_2_clicked();

    void on_pushButton_50_clicked();

    void on_label_22_linkActivated(const QString &link);

    void on_pushButton_49_clicked();

    void on_see_complain_customContextMenuRequested(const QPoint &pos);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_34_clicked();

    void on_pushButton_51_clicked();

    void on_tableView_11_activated(const QModelIndex &index);

    void on_tableView_11_clicked(const QModelIndex &index);

    void on_tableView_11_doubleClicked(const QModelIndex &index);

    void on_tableView_11_entered(const QModelIndex &index);

    void on_tableView_11_iconSizeChanged(const QSize &size);

    void on_tableView_11_pressed(const QModelIndex &index);

    void on_tableView_11_viewportEntered();

    void on_tableView_11_windowTitleChanged(const QString &title);

    void on_tableView_4_activated(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_115_clicked();

    void on_pushButton_116_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_95_clicked();

    void on_pushButton_52_clicked();

    void on_back_sup_menu_clicked();

    void on_back_sup_menu_2_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_55_clicked();

    void on_ok_sup_10_clicked();

    void on_pushButton_119_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_121_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_71_clicked();

    void on_back_sup_menu_3_clicked();

    void on_pushButton_343_clicked();

    void on_back_sup_menu_10_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_344_clicked();

    void on_back_sup_menu_11_clicked();

    void on_pushButton_123_clicked();

    void on_tableView_21_activated(const QModelIndex &index);

    void on_pushButton_56_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_118_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_127_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_132_clicked();

    void on_back_sup_menu_4_clicked();

    void on_pushButton_133_clicked();

    void on_ok_sup_11_clicked();

    void on_pushButton_135_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_134_clicked();

    void on_pushButton_130_clicked();

    void on_bus_Availability_activated(int index);

    void on_label_113_linkActivated(const QString &link);

    void on_stackedWidget_currentChanged(int arg1);

    void on_back_sup_menu_5_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_120_clicked();

    void on_pushButton_136_clicked();

    void on_back_sup_menu_6_clicked();

    void on_pushButton_137_clicked();

private:
    Ui::MainWindow *ui;
    QString type,remove_bus_for,com_update_drop,Sl_nooo,up_guest;
    QString email,password,up_sup,update_cmp_sup,rch_update,remove_bus_regis;
    QString show_bus_for,sl_solve,update_cmp_stu,update_cmp_tea,update_cmp_staff,update_cmp_helper,update_cmp_driver;
    QString schd_course_id, schd_for, schd_from, schd_to, schd_bus_no, time_edit,remove_schd_for, remove_schd_course_id,s_src_schd_from,s_src_schd_to,s_src_schd_for;
    QString st_src_schd_from,st_src_schd_to,st_src_schd_for,t_src_schd_from,t_src_schd_to,t_src_schd_for;
    QString st_name, st_id, st_phn, st_mail, st_pass,st_confirm_pass, login_st_mail, login_st_pass;
    QString t_name, t_id, t_phn, t_mail, t_pass, t_confirm_pass, login_t_mail, login_t_pass;
    QString sup_name, sup_id, sup_phn, sup_pass, sup_confirm_pass,login_sup_id,login_sup_pass,remove_sup_id,remove_sup_pass,sup_com;
    QString student_com, teacher_com, staff_com;
    QString staff_name, staff_id, staff_phn, staff_mail, staff_pass, staff_confirm_pass, login_staff_mail, login_staff_pass;
    QString id_cr, pass_cr,cng_cr_id,cng_cr_pass;
    QString name_dr, id_dr, bus_dr, pass_dr,con_pass_dr,lic_dr,phone_dr,remove_dr_id,remove_dr_pass,driver_pass,driver_login_pass,driver_login_id,dr_com;
    QString check_pass, check_con_pass;
    QString bus_no, bus_reg_no, bus_colour, bus_model,add_bus_for,remove_bus_no,remove_bus_reg;
    QString hlp_phone,hlp_name,hlp_id,remove_helper_name,remove_helper_phone,helper_login_name,helper_login_phone;
    QSqlDatabase info;
    QString cheak,cheak1,Sl,sl_t,sl_s,dr_sl,hlp_sl,sup_sl,seat_UP,view_c_drop,show_bus_for_cr,helper_bus_for1,guest_sug,helper_bus_for,helper_course_id,bus_Availability,helper_com;
};
#endif // MAINWINDOW_H
