#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> stackedWidget -> setCurrentIndex(0);
    info=QSqlDatabase::addDatabase("QSQLITE");
    info.setDatabaseName("C:/Users/shaha/Desktop/Final Project v11/OOP_BUS.db");
    info.open();
    qDebug()<<info.isOpen();

}

MainWindow::~MainWindow()
{
    delete ui;
    info.close();
}

void MainWindow::on_pushButton_clicked()
{
    type= ui->comboBox->currentText();
    if(type=="  Head / Chairman"){
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_chairman->setCurrentIndex(0);
    }
    else if( type=="  Supervisor"){
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(type=="  Driver"){
        ui->stackedWidget->setCurrentIndex(27);
    }
    else if(type=="  Bus Assistant"){
        ui->stackedWidget->setCurrentIndex(34);
    }
    else if(type=="  Student"){
        ui->stackedWidget->setCurrentIndex(5);
    }
    else if(type=="  Teacher"){
        ui->stackedWidget->setCurrentIndex(8);
    }
    else if(type=="  Staff"){
        ui->stackedWidget->setCurrentIndex(11);
    }
    else if(type=="  Guest"){
        ui->stackedWidget->setCurrentIndex(47);
        QSqlQuery q_dlt;
        q_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q_user;
        q_user.exec("INSERT INTO user_cheak (active,serial) VALUES('GUEST','1')");
        //ui->stackedWidget->setCurrentIndex(6);
    }

}


void MainWindow::on_Back_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Reg_sts_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}




void MainWindow::on_Reg_con_sts_clicked()
{
    check_pass= ui->pass_st->text();
    check_con_pass = ui->con_pass_st->text();
    if(check_pass==check_con_pass){
        st_name = ui->name_st->text();
        st_id = ui->id_st->text();
        st_mail = ui->gmail_st->text();
        st_phn = ui->phonr_st->text();
        st_pass = ui->pass_st->text();
        st_confirm_pass = ui->con_pass_st->text();

        QSqlQuery q2_student;
        q2_student.exec("INSERT INTO student_info (name,id,phone,email,password) VALUES('"+st_name+"','"+st_id+"','"+st_phn+"','"+st_mail+"','"+st_pass+"')");
        ui->stackedWidget->setCurrentIndex(5);

        ui->name_st->clear();
        ui->id_st->clear();
        ui->gmail_st->clear();
        ui->phonr_st->clear();
        ui->pass_st->clear();
        ui->con_pass_st->clear();
    }
    else{

    }
}


void MainWindow::on_Login_sts_clicked()
{
    login_st_mail = ui->login_st_mail->text();
    login_st_pass= ui->login_st_pass->text();

    QSqlQuery q1_student;
    q1_student.exec("SELECT * FROM student_info WHERE email='"+login_st_mail+"' AND password = '"+login_st_pass+"' ");
    if(q1_student.next())
    {
        qDebug()<<1;
        QSqlQuery q2_dlt;
        q2_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q22_user;
        q22_user.exec("INSERT INTO user_cheak (active,serial) VALUES('STUDENT','1')");
        ui->stackedWidget->setCurrentIndex(6);
    }
    else{
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
    }
    ui->login_st_mail->clear();
    ui->login_st_pass->clear();
}


void MainWindow::on_back_cr_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_Reg_con_sts_2_clicked()
{
    check_pass= ui->pass_t->text();
    check_con_pass = ui->con_pass_t->text();
    if(check_pass==check_con_pass){
        t_name = ui->name_t->text();
        t_phn = ui->phonr_t->text();
        t_mail = ui->gmail_t->text();
        t_pass = ui->pass_t->text();
        t_confirm_pass = ui->con_pass_t->text();


        QSqlQuery q1_teacher;
        q1_teacher.exec("INSERT INTO teacher_info (name,phone,email,password) VALUES('"+t_name+"','"+t_phn+"','"+t_mail+"','"+t_pass+"')");
        ui->stackedWidget->setCurrentIndex(8);

        ui->name_t->clear();
        ui->gmail_t->clear();
        ui->phonr_t->clear();
        ui->pass_t->clear();
        ui->con_pass_t->clear();
    }
}


void MainWindow::on_back_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_hlp_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);
}


void MainWindow::on_back_sup_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_SUP_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_Reg_con_sts_3_clicked()
{
    check_pass= ui->pass_staff->text();
    check_con_pass = ui->con_pass_staff->text();
    if(check_pass==check_con_pass){
        staff_name = ui->name_staff->text();
        staff_phn = ui->phonr_staff->text();
        staff_mail = ui->gmail_staff->text();
        staff_pass = ui->pass_staff->text();
        staff_confirm_pass = ui->con_pass_staff->text();



        QSqlQuery q1_staff;
        q1_staff.exec("INSERT INTO staff_info (name,phone,email,password) VALUES('"+staff_name+"','"+staff_phn+"','"+staff_mail+"','"+staff_pass+"')");
        ui->stackedWidget->setCurrentIndex(11);

        ui->name_staff->clear();
        ui->gmail_staff->clear();
        ui->phonr_staff->clear();
        ui->pass_staff->clear();
        ui->con_pass_staff->clear();
    }


}


void MainWindow::on_Back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Reg_sts_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_Back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Reg_sts_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_Login_sts_3_clicked()
{
    login_t_mail = ui->login_t_mail->text();
    login_t_pass= ui->login_t_pass->text();

    QSqlQuery q2_teacher;
    q2_teacher.exec("SELECT * FROM teacher_info WHERE email='"+login_t_mail+"' AND password = '"+login_t_pass+"' ");
    if(q2_teacher.next())
    {
        qDebug()<<1;
        QSqlQuery q5_dlt;
        q5_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q4_user;
        q4_user.exec("INSERT INTO user_cheak (active,serial) VALUES('TEACHER','1')");
        ui->stackedWidget->setCurrentIndex(9);
    }
    else{
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
    }
    //ui->stackedWidget->setCurrentIndex(0);
    //code for teacher info read

    ui->login_t_mail->clear();
    ui->login_t_pass->clear();
}


void MainWindow::on_Login_sts_2_clicked()
{
    login_staff_mail = ui->login_staff_mail->text();
    login_staff_pass= ui->login_staff_pass->text();

    QSqlQuery q2_staff;
    q2_staff.exec("SELECT * FROM staff_info WHERE email='"+login_staff_mail+"' AND password = '"+login_staff_pass+"' ");
    if(q2_staff.next())
    {
        qDebug()<<1;
        QSqlQuery q3_dlt;
        q3_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q3_user;
        q3_user.exec("INSERT INTO user_cheak (active,serial) VALUES('STAFF','1')");
        ui->stackedWidget->setCurrentIndex(12);
    }
    else{
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
    }
    //ui->stackedWidget->setCurrentIndex(0);


    ui->login_staff_mail->clear();
    ui->login_staff_pass->clear();
}


void MainWindow::on_logic_cr_clicked()
{
    id_cr = ui->id_cr->text();
    pass_cr = ui->pass_cr->text();

    QSqlQuery q1_chairman;
    q1_chairman.exec("SELECT * FROM Chairman WHERE email='"+id_cr+"' AND password = '"+pass_cr+"' ");
    if(q1_chairman.next())
    {
        qDebug()<<1;
        ui->stackedWidget_chairman->setCurrentIndex(1);
    }
    else{
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
        ui->stackedWidget_chairman->setCurrentIndex(0);
    }

   /* if(id_cr=="Nazmul Arefin" && pass_cr=="123"){
        ui->stackedWidget_chairman->setCurrentIndex(1);
    }*/

    ui->id_cr->clear();
    ui->pass_cr->clear();
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);
}




void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(3);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(4);

}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(5);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_3);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_3->setModel(modal);
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView->setModel(modal);
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_2);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_2->setModel(modal);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(1);
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(0);
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView);
    modal->setQuery(QString("select name,id,phone,email from student_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("id"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView->setModel(modal);
}


void MainWindow::on_pushButton_17_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_2);
    modal->setQuery(QString("select name,phone,email from teacher_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_2->setModel(modal);
}


void MainWindow::on_pushButton_18_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_3);
    modal->setQuery(QString("select name,phone,email from staff_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_3->setModel(modal);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(6);
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(1);
}


void MainWindow::on_back_sup_2_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(1);
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_rs);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_rs->setModel(modal);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(7);
}


void MainWindow::on_back_sup_3_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(1);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(8);
}


void MainWindow::on_login_SUP_clicked()
{
    login_sup_id = ui->login_sup_id->text();
    login_sup_pass = ui->login_sup_pass->text();

    QSqlQuery q2_sup;
    q2_sup.exec("SELECT * FROM Supervisor_info  WHERE ID='"+login_sup_id+"' AND Password = '"+login_sup_pass+"' ");
    if(q2_sup.next())
    {
        qDebug()<<1;
        QSqlQuery q1_dlt;
        q1_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q11_user;
        q11_user.exec("INSERT INTO user_cheak (active,serial) VALUES('SUPERVISOR','1')");
        ui->stackedWidget->setCurrentIndex(15);
    }
    else
    {
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
    }
    //if database read ui->stackedWidget->setCurrentIndex(15);

    ui->login_sup_id->clear();
    ui->login_sup_pass->clear();
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}


void MainWindow::on_back_sup_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_23);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_23->setModel(modal);
}


void MainWindow::on_back_sup_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_22);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_22->setModel(modal);
}


void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_84_clicked()
{
    cheak=("select active from user_cheak LIMIT 1");
    QSqlQuery query(cheak);
    if(query.exec())
    {
        if(query.next())
        {
            cheak1=query.value(0).toString();
        }
    }
    if(cheak1=="DRIVER")
    {
        ui->stackedWidget->setCurrentIndex(29);
    }
    else if(cheak1=="TEACHER")
    {
        ui->stackedWidget->setCurrentIndex(9);
    }
    else if(cheak1=="STAFF")
    {
        ui->stackedWidget->setCurrentIndex(12);
    }
    else if(cheak1=="SUPERVISOR")
    {
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(cheak1=="HELPER")
    {
        ui->stackedWidget->setCurrentIndex(35);
    }
    else if(cheak1=="STUDENT")
    {
        ui->stackedWidget->setCurrentIndex(6);
    }
    else if(cheak1=="GUEST")
    {
        ui->stackedWidget->setCurrentIndex(47);
    }
}


void MainWindow::on_pushButton_88_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_7);
    modal->setQuery(QString("select name,id,phone,email from student_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("id"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_7->setModel(modal);
}


void MainWindow::on_pushButton_90_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_8);
    modal->setQuery(QString("select name,phone,email from teacher_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_8->setModel(modal);
}


void MainWindow::on_pushButton_92_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_9);
    modal->setQuery(QString("select name,phone,email from staff_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_9->setModel(modal);
}


void MainWindow::on_pushButton_83_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_pushButton_85_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}


void MainWindow::on_pushButton_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
}


void MainWindow::on_pushButton_93_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_9);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_9->setModel(modal);
}


void MainWindow::on_pushButton_91_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_8);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_8->setModel(modal);
}


void MainWindow::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_7);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_7->setModel(modal);
}


void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_81_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(9);
}


void MainWindow::on_pushButton_96_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_11);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_11->setModel(modal);
}


void MainWindow::on_pushButton_94_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_10);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_10->setModel(modal);
}


void MainWindow::on_pushButton_82_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);
}


void MainWindow::on_pushButton_101_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_13);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_13->setModel(modal);
}


void MainWindow::on_pushButton_99_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_12);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_12->setModel(modal);
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(10);
}


void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(11);
}


void MainWindow::on_pushButton_105_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_15);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_15->setModel(modal);
}


void MainWindow::on_pushButton_103_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_14);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_14->setModel(modal);
}


void MainWindow::on_Back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_107_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_16);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_16->setModel(modal);
}


void MainWindow::on_pushButton_86_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);
}


void MainWindow::on_pushButton_109_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_17);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_17->setModel(modal);
}


void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(12);
}


void MainWindow::on_ok_sup_clicked()
{
    sup_pass= ui->pass_staff->text();
    sup_confirm_pass = ui->con_pass_staff->text();
    if(sup_pass==sup_confirm_pass){
        sup_name = ui->name_sup->text();
        sup_id = ui->id_sup->text();
        sup_phn = ui->phone_sup->text();
        sup_pass = ui->pass_sup->text();
        sup_confirm_pass = ui->con_pass_sup->text();


        //database code
        QSqlQuery q1_sup;
        q1_sup.exec("INSERT INTO Supervisor_info (Name,ID,Phone,Password) VALUES('"+sup_name+"','"+sup_id+"','"+sup_phn+"','"+sup_pass+"')");

        QMessageBox msgBox;
        msgBox.setText("ADDED SUCCESSFULLY");
        msgBox.exec();

        ui->stackedWidget_chairman->setCurrentIndex(1);

        ui->name_sup->clear();
        ui->id_sup->clear();
        ui->phone_sup->clear();
        ui->pass_sup->clear();
        ui->con_pass_sup->clear();
    }
}


void MainWindow::on_pushButton_41_clicked()
{
    remove_sup_id = ui->remove_sup_id->text();
    // = ui->remove_sup_pass->text();

    QSqlQuery q3_sup;
    q3_sup.exec("delete from Supervisor_info where ID='"+remove_sup_id+"' ");

    QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
    //ui->stackedWidget_chairman->setCurrentIndex(1);

    ui->remove_sup_id->clear();
    //ui->remove_sup_pass->clear();
}


void MainWindow::on_ok_sup_3_clicked()
{
    cng_cr_id = ui->cng_cr_id->text();
    cng_cr_pass = ui->cng_cr_pass->text();

    QSqlQuery q5_cr;
    q5_cr.exec("delete from Chairman where email='"+id_cr+"' AND password = '"+pass_cr+"' ");
    q5_cr.exec("INSERT INTO Chairman (email,password) VALUES('"+cng_cr_id+"','"+cng_cr_pass+"')");
    QMessageBox msgBox;
    msgBox.setText("CHAIRMAN CHANGED SUCCESSFULLY");
    msgBox.exec();

    //QSqlQuery q6_cr;
    ui->stackedWidget->setCurrentIndex(0);
    //database for replacing cr then ui->stackedWidget_chairman->setCurrentIndex(0);

    ui->cng_cr_id->clear();
    ui->cng_cr_pass->clear();
}


void MainWindow::on_Login_sts_4_clicked()
{
    driver_login_id = ui->driver_id->text();
    driver_login_pass = ui->driver_pass->text();

    QSqlQuery q2_Driver;
    q2_Driver.exec("SELECT * FROM Driver_info WHERE ID='"+driver_login_id+"' AND password = '"+driver_login_pass+"' ");
    if(q2_Driver.next())
    {
        qDebug()<<1;
        QSqlQuery q8_dlt;
        q8_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q8_user;
        q8_user.exec("INSERT INTO user_cheak (active,serial) VALUES('DRIVER','1')");
        ui->stackedWidget->setCurrentIndex(29);
    }
    else{
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
    }
    ui->driver_id->clear();
    ui->driver_pass->clear();
}


void MainWindow::on_reg_con_dr_clicked()
{
    name_dr = ui->name_dr->text();
    id_dr = ui->id_dr->text();
    phone_dr =ui->phone_dr->text();
    bus_dr = ui->bus_dr->text();
    lic_dr = ui->lic_dr->text();
    pass_dr = ui->pass_dr->text();
    con_pass_dr = ui->con_pass_dr->text();

    QSqlQuery q1_driver;
    q1_driver.exec("INSERT INTO Driver_info (name,ID,phone,busnum,licence,password) VALUES('"+name_dr+"','"+id_dr+"','"+phone_dr+"','"+bus_dr+"','"+lic_dr+"','"+pass_dr+"')");
    QMessageBox msgBox;
    msgBox.setText("ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(15);
    ui->name_dr->clear();
    ui->id_dr->clear();
    ui->phone_dr->clear();
    ui->bus_dr->clear();
    ui->lic_dr->clear();
    ui->pass_dr->clear();
    ui->con_pass_dr->clear();
}


void MainWindow::on_pushButton_100_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_13);
    modal->setQuery(QString("select Name,ID,Phone from Supervisor_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("Name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("ID"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("Phone"));

    ui->tableView_13->setModel(modal);

}


void MainWindow::on_label_14_linkActivated(const QString &link)
{

}


void MainWindow::on_label_5_linkActivated(const QString &link)
{

}


void MainWindow::on_pushButton_104_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_15);
    modal->setQuery(QString("select Name,ID,Phone from Supervisor_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("Name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("ID"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("Phone"));

    ui->tableView_15->setModel(modal);
}





void MainWindow::on_pushButton_97_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_11);
    modal->setQuery(QString("select email from Chairman"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_11->setModel(modal);
}


void MainWindow::on_pushButton_102_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_14);
    modal->setQuery(QString("select name,ID,phone,licence,busnum,password from Driver_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("ID"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("licence"));
    modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("busnum"));
    modal-> setHeaderData(5, Qt:: Horizontal ,QObject::tr("password"));

    ui->tableView_14->setModel(modal);

}


void MainWindow::on_bus_save_clicked()
{
    add_bus_for = ui->add_bus_for->currentText();//eitar kaj korte hbe database e
    bus_no = ui->bus_no_ad->text();
    bus_reg_no = ui->bus_reg_no->text();
    bus_colour = ui->bus_col->text();
    bus_model = ui->bus_model->text();

    QMessageBox msgBox;
    msgBox.setText("ADDED SUCCESSFULLY");
    msgBox.exec();
    if(add_bus_for=="STUDENT"){
        //DATABASE FOR ADD BUS FOR STUDENT
        QSqlQuery q1_bus;
        q1_bus.exec("INSERT INTO student_bus (busno,busreg,colour,model) VALUES('"+bus_no+"','"+bus_reg_no+"','"+bus_colour+"','"+bus_model+"')");
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(add_bus_for=="TEACHER"){
        //DATABASE FOR ADD BUS FOR TEACHER
        QSqlQuery q2_bus;
        q2_bus.exec("INSERT INTO teacher_bus (busno,busreg,colour,model) VALUES('"+bus_no+"','"+bus_reg_no+"','"+bus_colour+"','"+bus_model+"')");
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(add_bus_for=="STAFF"){
        //DATABASE FOR ADD BUS FOR STAFF
        QSqlQuery q3_bus;
        q3_bus.exec("INSERT INTO stuff_bus (busno,busreg,colour,model) VALUES('"+bus_no+"','"+bus_reg_no+"','"+bus_colour+"','"+bus_model+"')");
        ui->stackedWidget->setCurrentIndex(15);
    }

    QSqlQuery q1_bus;
    q1_bus.exec("INSERT INTO Bus_info (busno,busreg,colour,model) VALUES('"+bus_no+"','"+bus_reg_no+"','"+bus_colour+"','"+bus_model+"')");

    ui->stackedWidget->setCurrentIndex(15);
    ui->bus_no_ad->clear();
    ui->bus_reg_no->clear();
    ui->bus_col->clear();
    ui->bus_model->clear();
}



void MainWindow::on_pushButton_106_clicked()
{
    show_bus_for = ui->show_bus_for->currentText();
    if(show_bus_for=="STUDENT"){
        //DATABASE FOR show BUS FOR STUDENT
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_16);
        modal->setQuery(QString("select busno,busreg,colour,model from student_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_16->setModel(modal);
    }
    else if(show_bus_for=="TEACHER"){
        //DATABASE FOR show BUS FOR teacher
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_16);
        modal->setQuery(QString("select busno,busreg,colour,model from teacher_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_16->setModel(modal);
    }
    else if(show_bus_for=="STAFF"){
        //DATABASE FOR show BUS FOR staff
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_16);
        modal->setQuery(QString("select busno,busreg,colour,model from stuff_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_16->setModel(modal);
    }

}


void MainWindow::on_pushButton_108_clicked()
{
    show_bus_for_cr = ui->show_bus_for_cr->currentText();
    if(show_bus_for_cr=="STUDENT"){
        //DATABASE FOR show BUS FOR STUDENT
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_17);
        modal->setQuery(QString("select busno,busreg,colour,model from student_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_17->setModel(modal);
    }
    else if(show_bus_for_cr=="TEACHER"){
        //DATABASE FOR show BUS FOR teacher
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_17);
        modal->setQuery(QString("select busno,busreg,colour,model from teacher_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_17->setModel(modal);
    }
    else if(show_bus_for_cr=="STAFF"){
        //DATABASE FOR show BUS FOR staff
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_17);
        modal->setQuery(QString("select busno,busreg,colour,model from stuff_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_17->setModel(modal);
    }
    /*QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_17);
    modal->setQuery(QString("select busno,busreg,colour,model from Bus_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

    ui->tableView_17->setModel(modal);*/
}


void MainWindow::on_pushButton_98_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_12);
    modal->setQuery(QString("select name,ID,phone,licence,busnum,password from Driver_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("ID"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("licence"));
    modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("busnum"));
    modal-> setHeaderData(5, Qt:: Horizontal ,QObject::tr("password"));

    ui->tableView_12->setModel(modal);
}



void MainWindow::on_ok_sup_7_clicked()
{
    remove_bus_regis = ui->remove_bus_reg->text();

    remove_bus_for = ui->remove_bus_for->currentText();

    if(remove_bus_for == "STUDENT"){
        QSqlQuery qq5_sup;
        qq5_sup.exec("delete from student_bus where busreg = '"+remove_bus_regis+"' ");

        QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
        ui->stackedWidget->setCurrentIndex(15);
        ui->remove_bus_reg->clear();
    }
    else if(remove_bus_for == "TEACHER"){
    QSqlQuery qq5_sup;
    qq5_sup.exec("delete from teacher_bus where busreg = '"+remove_bus_regis+"' ");

    QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
    ui->stackedWidget->setCurrentIndex(15);
    ui->remove_bus_reg->clear();
    }
    else if(remove_bus_for == "STAFF"){
    QSqlQuery qq5_sup;
    qq5_sup.exec("delete from stuff_bus where busreg = '"+remove_bus_regis+"' ");

    QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
    //ui->stackedWidget->setCurrentIndex(15);
    ui->remove_bus_reg->clear();
    }
}


void MainWindow::on_ok_sup_8_clicked()
{
    remove_dr_id = ui->remove_dr_id->text();
    //remove_dr_pass = ui->remove_dr_pass->text();

    QSqlQuery q4_sup;
    q4_sup.exec("delete from Driver_info where ID='"+remove_dr_id+"' ");

    QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
    //ui->stackedWidget->setCurrentIndex(15);
    ui->remove_dr_id->clear();
}


void MainWindow::on_pushButton_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}


void MainWindow::on_pushButton_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(31);
}


void MainWindow::on_pushButton_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}


void MainWindow::on_pushButton_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_hlp_save_clicked()
{
    hlp_name = ui->hlp_name->text();
    hlp_phone = ui->hlp_phone->text();
    hlp_id = ui->hlp_id->text();

    QSqlQuery q1_helper;
    q1_helper.exec("INSERT INTO helper_info (name,phone,id) VALUES('"+hlp_name+"','"+hlp_phone+"','"+hlp_id+"')");

    QMessageBox msgBox;
    msgBox.setText("ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(29);
    ui->hlp_name->clear();
    ui->hlp_phone->clear();
    ui->hlp_id->clear();
}


void MainWindow::on_back_sup_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_25);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_25->setModel(modal);
}


void MainWindow::on_ok_sup_9_clicked()
{
    remove_helper_name = ui->remove_helper_name->text();
    remove_helper_phone = ui->remove_helper_phone->text();

    QSqlQuery q3_bus;
    q3_bus.exec("delete from helper_info where name='"+remove_helper_name+"' AND phone = '"+remove_helper_phone+"' ");

    QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
    //ui->stackedWidget->setCurrentIndex(29);
    ui->remove_helper_name->clear();
    ui->remove_helper_phone->clear();
}

void MainWindow::on_pushButton_110_clicked()
{
    dr_com = ui->driver_complain_box->toPlainText();
    update_cmp_driver="UNSOLVED";

    QSqlQuery q6_driver;
    q6_driver.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+dr_com+"','"+update_cmp_driver+"')");

    QMessageBox msgBox;
    msgBox.setText("COMPLAIN ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(29);

    ui->driver_complain_box->clear();
}


void MainWindow::on_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);
}


void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(33);

}


void MainWindow::on_pushButton_112_clicked()
{
    sup_com = ui->sup_complain_box->toPlainText();
    update_cmp_sup = "UNSOLVED";

    QSqlQuery qu66_sup;
    qDebug()<<(qu66_sup.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+sup_com+"','"+update_cmp_sup+"')"));
    //q6_sup.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+sup_com+"','"+up_sup+"')");

    QMessageBox msgBox;
    msgBox.setText("COMPLAIN ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(15);

    ui->sup_complain_box->clear();
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(13);
}


void MainWindow::on_pushButton_48_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(1);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_cmp);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_cmp->setModel(modal);
}


void MainWindow::on_back_cr_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_logic_cr_2_clicked()
{
    helper_login_name = ui->helper_login_name->text();
    helper_login_phone = ui->helper_login_phone->text();

    QSqlQuery q2_helper;
    q2_helper.exec("SELECT * FROM helper_info WHERE name='"+helper_login_name+"' AND phone = '"+helper_login_phone+"' ");
    if(q2_helper.next())
    {
        qDebug()<<1;
        QSqlQuery q7_dlt;
        q7_dlt.exec("delete from user_cheak where serial='1'");

        QSqlQuery q7_user;
        q7_user.exec("INSERT INTO user_cheak (active,serial) VALUES('HELPER','1')");
        ui->stackedWidget->setCurrentIndex(35);
    }
    else{
        QMessageBox::critical(this,tr(" "),tr("<center><h3>Login Failed</h2></center> Your email or password is incorrect.<br><center>PLease try again.</center>"));
    }
    ui->helper_login_name->clear();
    ui->helper_login_phone->clear();
}


void MainWindow::on_pushButton_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(34);
}




void MainWindow::on_pushButton_49_clicked()
{
    view_c_drop=ui->view_c_drop->currentText();
    if(view_c_drop==" Complain" )
    {
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_cmp);
        modal->setQuery(QString("select Sl_no,complain,Update_cmp from complain_box"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("Sl_no"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("complain"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("Update_cmp"));

        ui->tableView_cmp->setModel(modal);

    }
    else if(view_c_drop==" Suggestion")
    {

        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_cmp);
        modal->setQuery(QString("select Ssl_no,guest_sug,update_sug from suggestion"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("Ssl_no"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("guest_sug"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("update_sug"));

        ui->tableView_cmp->setModel(modal);
    }
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_pushButton_51_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_pushButton_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(36);
}


void MainWindow::on_pushButton_114_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(2);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_18);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_18->setModel(modal);
}


void MainWindow::on_pushButton_117_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_115_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_18);
    modal->setQuery(QString("select name,phone,id from helper_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("id"));

    ui->tableView_18->setModel(modal);
}


void MainWindow::on_pushButton_116_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_19);
    modal->setQuery(QString("select name,phone,id from helper_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("id"));

    ui->tableView_19->setModel(modal);
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget_chairman->setCurrentIndex(14);
}


void MainWindow::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);
}


void MainWindow::on_pushButton_95_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_10);
    modal->setQuery(QString("select email from Chairman"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("email"));

    ui->tableView_10->setModel(modal);
}


void MainWindow::on_pushButton_52_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_5);
    modal->setQuery(QString("select complain from complain_box"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("complain"));

    ui->tableView_5->setModel(modal);
}


void MainWindow::on_back_sup_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_20);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_20->setModel(modal);
}


void MainWindow::on_back_sup_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_pushButton_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_pushButton_54_clicked()
{

    schd_course_id = ui->schd_course_id->text();
    schd_for = ui->schd_for->currentText();
    schd_from = ui->schd_from->currentText();
    schd_to = ui->schd_to->currentText();
    schd_bus_no = ui->schd_bus_no->text();
    time_edit = ui->timeEdit->text();
    seat_UP = "SEAT AVAILABLE";
    QMessageBox msgBox;
    msgBox.setText("ADDED SUCCESSFULLY");
    msgBox.exec();
    if(schd_for=="STUDENT"){
        //DATABASE FOR add schedule FOR STUDENT
        QSqlQuery q1_schd;
        q1_schd.exec("INSERT INTO student_sdl (student_id,student_from,student_to,student_busno,student_time,seat_update) VALUES('"+schd_course_id+"','"+schd_from+"','"+schd_to+"','"+schd_bus_no+"','"+time_edit+"','"+seat_UP+"')");
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(schd_for=="TEACHER"){
        //DATABASE FOR add schedulS FOR teacher
        QSqlQuery q2_schd;
        q2_schd.exec("INSERT INTO teacher_sdl (teacher_id,teacher_from,teacher_to,teacher_busno,teacher_time,seat_update_T) VALUES('"+schd_course_id+"','"+schd_from+"','"+schd_to+"','"+schd_bus_no+"','"+time_edit+"','"+seat_UP+"')");
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(schd_for=="STAFF"){
        //DATABASE FOR add schedul FOR staff
        QSqlQuery q3_schd;
        q3_schd.exec("INSERT INTO staff_sdl (staff_id,staff_from,staff_to,staff_busno,staff_time,seat_update_S) VALUES('"+schd_course_id+"','"+schd_from+"','"+schd_to+"','"+schd_bus_no+"','"+time_edit+"','"+seat_UP+"')");
        ui->stackedWidget->setCurrentIndex(15);
    }
    ui->schd_course_id->clear();
    ui->schd_bus_no->clear();

}


void MainWindow::on_pushButton_53_clicked()
{
    //add bus schedule load table
    schd_for = ui->schd_for->currentText();
    if(schd_for=="STUDENT"){
        //DATABASE FOR show BUS FOR STUDENT
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_6);
        modal->setQuery(QString("select busno,busreg,colour,model from student_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_6->setModel(modal);
    }
    else if(schd_for=="TEACHER"){
        //DATABASE FOR show BUS FOR teacher
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_6);
        modal->setQuery(QString("select busno,busreg,colour,model from teacher_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_6->setModel(modal);
    }
    else if(schd_for=="STAFF"){
        //DATABASE FOR show BUS FOR staff
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_6);
        modal->setQuery(QString("select busno,busreg,colour,model from stuff_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_6->setModel(modal);

    }
}


void MainWindow::on_pushButton_55_clicked()
{
    remove_schd_for = ui->remove_schd_for->currentText();
    if(remove_schd_for=="STUDENT"){
        //show student schdule
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_20);
        modal->setQuery(QString("select student_id,student_from,student_to,student_busno,student_time from student_sdl"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("student_id"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("student_from"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("student_to"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("student_busno"));
        modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("student_time"));

        ui->tableView_20->setModel(modal);


    }
    else if(remove_schd_for=="TEACHER"){
        //show TEACHER schdule
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_20);
        modal->setQuery(QString("select teacher_id,teacher_from,teacher_to,teacher_busno,teacher_time from teacher_sdl"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("teacher_id"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("teacher_from"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("teacher_to"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("teacher_busno"));
        modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("teacher_time"));

        ui->tableView_20->setModel(modal);
    }
    else if(remove_schd_for=="STAFF"){
        //show STAFF schdule
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_20);
        modal->setQuery(QString("select staff_id,staff_from,staff_to,staff_busno,staff_time from staff_sdl"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("staff_id"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("staff_from"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("staff_to"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("staff_busno"));
        modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("staff_time"));

        ui->tableView_20->setModel(modal);
    }
}


void MainWindow::on_ok_sup_10_clicked()
{
    remove_schd_course_id = ui->remove_schd_course_id->text();
    if(remove_schd_for=="STUDENT"){
        //show student schdule
        QSqlQuery q7_schd;
        q7_schd.exec("delete from student_sdl where student_id='"+remove_schd_course_id+"'");

        QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
        //ui->stackedWidget->setCurrentIndex(15);
    }
    else if(remove_schd_for=="TEACHER"){
        //show TEACHER schdule
        QSqlQuery q8_schd;
        q8_schd.exec("delete from teacher_sdl where teacher_id='"+remove_schd_course_id+"'");

        QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
        //ui->stackedWidget->setCurrentIndex(15);
    }
    else if(remove_schd_for=="STAFF"){
        //show STAFF schdule
        QSqlQuery q9_schd;
        q9_schd.exec("delete from staff_sdl where staff_id='"+remove_schd_course_id+"'");

        QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
        //ui->stackedWidget->setCurrentIndex(15);
    }
    ui->remove_schd_course_id->clear();
}


void MainWindow::on_pushButton_119_clicked()
{
    student_com = ui->student_complain_box->toPlainText();
    update_cmp_stu="UNSOLVED";

    //add complain to database
    QSqlQuery q7_stu;
    qDebug()<<q7_stu.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+student_com+"','"+update_cmp_stu+"')");

    QMessageBox msgBox;
    msgBox.setText("COMPLAIN ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(6);

    ui->student_complain_box->clear();

}


void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);
}


void MainWindow::on_pushButton_121_clicked()
{;
    teacher_com = ui->teacher_complain_box->toPlainText();
    update_cmp_tea="UNSOLVED";


    //add complain to database
    QSqlQuery q7_stu;
    qDebug()<<q7_stu.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+teacher_com+"','"+update_cmp_tea+"')");

    QMessageBox msgBox;
    msgBox.setText("COMPLAIN ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(9);

    ui->teacher_complain_box->clear();
}


void MainWindow::on_pushButton_65_clicked()
{
    ui->stackedWidget->setCurrentIndex(39);
}


void MainWindow::on_pushButton_70_clicked()
{
    ui->stackedWidget->setCurrentIndex(40);
}


void MainWindow::on_pushButton_71_clicked()
{
    st_src_schd_from = ui->st_src_schd_from->currentText();
    st_src_schd_to = ui->st_src_schd_to->currentText();
    //code for show student bus by using from and to

   // QString cheak = ui-> tableView->model()->data(index).toString();

    QSqlQuery q9;
    q9.exec("select *from student_sdl where student_from='"+st_src_schd_from+"' and student_to='"+st_src_schd_to+"'");

    if(q9.exec())
    {
        while(q9.next())
        {
            QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_21);
            modal->setQuery(QString("select student_id,student_from,student_to,student_busno,student_time,seat_update from student_sdl where student_from='"+st_src_schd_from+"' and student_to='"+st_src_schd_to+"'"));
            modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("student_id"));
            modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("student_from"));
            modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("student_to"));
            modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("student_busno"));
            modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("student_time"));
            modal-> setHeaderData(5, Qt:: Horizontal ,QObject::tr("seat_update"));

            ui->tableView_21->setModel(modal);
        }
    }

}


void MainWindow::on_back_sup_menu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_21);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_21->setModel(modal);
}


void MainWindow::on_pushButton_343_clicked()
{
    t_src_schd_from = ui->t_src_schd_from->currentText();
    t_src_schd_to = ui->t_src_schd_to->currentText();
    //code for show teacher bus by using from and to
    QSqlQuery q10;
    q10.exec("select *from teacher_sdl where teacher_from='"+t_src_schd_from+"' and teacher_to='"+t_src_schd_to+"'");

    if(q10.exec())
    {
        while(q10.next())
        {
            QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_64);
            modal->setQuery(QString("select teacher_id,teacher_from,teacher_to,teacher_busno,teacher_time,seat_update_T from teacher_sdl where teacher_from='"+t_src_schd_from+"' and teacher_to='"+t_src_schd_to+"'"));
            modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("teacher_id"));
            modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("teacher_from"));
            modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("teacher_to"));
            modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("teacher_busno"));
            modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("teacher_time"));
            modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("seat_update_T"));

            ui->tableView_64->setModel(modal);
        }
    }
}


void MainWindow::on_back_sup_menu_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);



    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_64);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_64->setModel(modal);
}


void MainWindow::on_pushButton_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}


void MainWindow::on_pushButton_67_clicked()
{
    ui->stackedWidget->setCurrentIndex(43);
}


void MainWindow::on_pushButton_344_clicked()
{
     s_src_schd_from = ui->s_src_schd_from->currentText();
     s_src_schd_to = ui->s_src_schd_to->currentText();
     //code for show staff bus by using from and to
     QSqlQuery q11;
     q11.exec("select *from staff_sdl where staff_from='"+s_src_schd_from+"' and staff_to='"+s_src_schd_to+"'");

     if(q11.exec())
     {
        while(q11.next())
        {
            QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_65);
            modal->setQuery(QString("select staff_id,staff_from,staff_to,staff_busno,staff_time,seat_update_S from staff_sdl where staff_from='"+s_src_schd_from+"' and staff_to='"+s_src_schd_to+"'"));
            modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("staffr_id"));
            modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("staff_from"));
            modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("staff_to"));
            modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("staff_busno"));
            modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("staff_time"));
            modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("seat_update_S"));

            ui->tableView_65->setModel(modal);
        }
     }
}


void MainWindow::on_back_sup_menu_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

     QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_65);
     modal->setQuery(QString("select from blank"));
     modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
     ui->tableView_65->setModel(modal);
}


void MainWindow::on_pushButton_123_clicked()
{
    staff_com = ui->staff_complain_box->toPlainText();
     update_cmp_staff="UNSOLVED";


    //add complain to database
    QSqlQuery q7_staff;
    q7_staff.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+staff_com+"','"+update_cmp_staff+"')");

    QMessageBox msgBox;
    msgBox.setText("COMPLAIN ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(12);

    ui->staff_complain_box->clear();
}





void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}


void MainWindow::on_pushButton_60_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_63_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_68_clicked()
{
     ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_72_clicked()
{
     ui->stackedWidget->setCurrentIndex(44);
}


void MainWindow::on_pushButton_75_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_73_clicked()
{
     ui->stackedWidget->setCurrentIndex(45);
}


void MainWindow::on_pushButton_74_clicked()
{
     ui->stackedWidget->setCurrentIndex(46);
}


void MainWindow::on_pushButton_76_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}


void MainWindow::on_pushButton_77_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}


void MainWindow::on_pushButton_118_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_125_clicked()
{
    ui->stackedWidget->setCurrentIndex(48);
}


void MainWindow::on_pushButton_128_clicked()
{
    ui->stackedWidget->setCurrentIndex(47);
}


void MainWindow::on_pushButton_127_clicked()
{
    guest_sug = ui->guest_sug_box->toPlainText();

    up_guest = "UNSOLVED";

    //code for add sug. to database
    QSqlQuery q9_guest;
    q9_guest.exec("INSERT INTO suggestion (guest_sug,update_sug) VALUES('"+guest_sug+"' , '"+up_guest+"')");

    QMessageBox msgBox;
    msgBox.setText("SUGGESTION ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(47);

    ui->guest_sug_box->clear();
}


void MainWindow::on_pushButton_126_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_132_clicked()
{
    ui->stackedWidget->setCurrentIndex(49);
}


void MainWindow::on_back_sup_menu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(35);

    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_26);
    modal->setQuery(QString("select from blank"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("ENTER LOAD TABLE"));
    ui->tableView_26->setModel(modal);
}


void MainWindow::on_pushButton_133_clicked()
{
    helper_bus_for = ui->helper_bus_for->currentText();
    if(helper_bus_for=="STUDENT"){
        //SHOW STUDENT SCHEDULE
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_26);
        modal->setQuery(QString("select student_id,student_from,student_to,student_busno,student_time from student_sdl"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("student_id"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("student_from"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("student_to"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("student_busno"));
        modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("student_time"));

        ui->tableView_26->setModel(modal);
    }
    else if(helper_bus_for=="TEACHER"){
        //SHOW teacher SCHEDULE
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_26);
        modal->setQuery(QString("select teacher_id,teacher_from,teacher_to,teacher_busno,teacher_time from teacher_sdl"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("teacher_id"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("teacher_from"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("teacher_to"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("teacher_busno"));
        modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("teacher_time"));

        ui->tableView_26->setModel(modal);
    }
    else if(helper_bus_for=="STAFF"){
        //SHOW staff SCHEDULE
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_26);
        modal->setQuery(QString("select staff_id,staff_from,staff_to,staff_busno,staff_time from staff_sdl"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("staff_id"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("staff_from"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("staff_to"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("staff_busno"));
        modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("staff_time"));

        ui->tableView_26->setModel(modal);
    }
}


void MainWindow::on_ok_sup_11_clicked()
{
    helper_bus_for = ui->helper_bus_for->currentText();
    helper_course_id = ui->helper_course_id->text();
    bus_Availability = ui->bus_Availability->currentText();

    //database add for availability
    if(helper_bus_for=="STUDENT")
    {

        QSqlQuery qry11;
        qDebug()<< qry11.prepare("update student_sdl set seat_update = '"+bus_Availability+"' where student_id ='"+helper_course_id+"'");
        if(qry11.exec())
        {
            QMessageBox :: information(this,"Update Info.","Updated Successful");
        }

    }
    else if(helper_bus_for=="TEACHER"){
        //SHOW teacher SCHEDULE
        QSqlQuery qy12;
        qDebug()<<qy12.prepare("update teacher_sdl set seat_update_T = '"+bus_Availability+"' where teacher_id ='"+helper_course_id+"'");
        if(qy12.exec())
        {
            QMessageBox :: information(this,"Update Info.","Updated Successful");
        }
    }
    else if(helper_bus_for=="STAFF"){
        //SHOW staff SCHEDULE
        QSqlQuery qry3;
        qDebug()<<qry3.prepare("update staff_sdl set seat_update_S = '"+bus_Availability+"' where staff_id ='"+helper_course_id+"'");
        if(qry3.exec())
        {
            QMessageBox :: information(this,"Update Info.","Updated Successful");
        }
    }
    ui->stackedWidget->setCurrentIndex(35);
    ui->helper_course_id->clear();
}


void MainWindow::on_pushButton_135_clicked()
{
    ui->stackedWidget->setCurrentIndex(35);
}


void MainWindow::on_pushButton_129_clicked()
{
    ui->stackedWidget->setCurrentIndex(50);
}


void MainWindow::on_pushButton_134_clicked()
{
    helper_com = ui->helper_complain_box->toPlainText();
    update_cmp_helper="UNSOLVED";

    //code for add helper complain to database
    QSqlQuery q1000;
    q1000.exec("INSERT INTO complain_box (complain,Update_cmp) VALUES('"+helper_com+"','"+update_cmp_helper+"')");

    QMessageBox msgBox;
    msgBox.setText("COMPLAIN ADDED SUCCESSFULLY");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(35);

    ui->helper_complain_box->clear();//helper_complain_box
}


void MainWindow::on_pushButton_130_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}





void MainWindow::on_back_sup_menu_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_79_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_23);
    modal->setQuery(QString("select name,id,phone,licence,busnum,password from Driver_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("id"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("licence"));
    modal-> setHeaderData(4, Qt:: Horizontal ,QObject::tr("busnum"));
    modal-> setHeaderData(5, Qt:: Horizontal ,QObject::tr("password"));

    ui->tableView_23->setModel(modal);
}


void MainWindow::on_pushButton_78_clicked()
{
    remove_bus_for = ui->remove_bus_for->currentText();
    if(remove_bus_for=="STUDENT"){
        //show student schdule
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_22);
        modal->setQuery(QString("select busno,busreg,colour,model from student_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_22->setModel(modal);


    }
    else if(remove_bus_for=="TEACHER"){
        //show TEACHER schdule
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_22);
        modal->setQuery(QString("select busno,busreg,colour,model from teacher_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_22->setModel(modal);
    }
    else if(remove_bus_for=="STAFF"){
        //show STAFF schdule
        QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_22);
        modal->setQuery(QString("select busno,busreg,colour,model from stuff_bus"));
        modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("busno"));
        modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("busreg"));
        modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("colour"));
        modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("model"));

        ui->tableView_22->setModel(modal);
    }
}


void MainWindow::on_pushButton_80_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_rs);
    modal->setQuery(QString("select Name,ID,Phone,Password from Supervisor_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("Name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("ID"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("Phone"));
    modal-> setHeaderData(3, Qt:: Horizontal ,QObject::tr("Password"));

    ui->tableView_rs->setModel(modal);
}


void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_124_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel (ui->tableView_25);
    modal->setQuery(QString("select name,phone,id from helper_info"));
    modal-> setHeaderData(0, Qt:: Horizontal ,QObject::tr("name"));
    modal-> setHeaderData(1, Qt:: Horizontal ,QObject::tr("phone"));
    modal-> setHeaderData(2, Qt:: Horizontal ,QObject::tr("id"));

    ui->tableView_25->setModel(modal);
}


void MainWindow::on_pushButton_131_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_59_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_64_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_69_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_122_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_120_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_pushButton_136_clicked()
{
    sl_solve = ui->sl_solve->text();
    rch_update = "SOLVED";
    if(view_c_drop==" Complain"){
        //database for remove Complain

        QSqlQuery intel;
        intel.prepare("update complain_box set Update_cmp = '"+rch_update+"' where Sl_no ='"+sl_solve+"'");
        if(intel.exec()){
            QMessageBox :: information(this,"Update Info.","Updated Successful");
        }
    }
    else if(view_c_drop==" Suggestion"){
        //database for remove   Suggestion
        QSqlQuery intel2;
        intel2.prepare("update suggestion set update_sug = '"+rch_update+"' where Ssl_no ='"+sl_solve+"'");
        if(intel2.exec()){
            QMessageBox :: information(this,"Update Info.","Updated Successful");
        }
    }
    ui->sl_solve->clear();
}

void MainWindow::on_back_sup_menu_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}


void MainWindow::on_pushButton_137_clicked()
{
    ui->stackedWidget->setCurrentIndex(51);
}

