#include "admincontroller.h"
#include "ui_admincontroller.h"

AdminController::AdminController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminController)
{
    ui->setupUi(this);
    ui->lineEditSelectUser->setClearButtonEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    UserManager &userManager = UserManager::instance();
    QList<QVariantMap> users = userManager.getAllUsers();

    QStringList headers = {"序号","用户名","密码","邮箱","电话","角色","注册时间","更新时间"};
    QStringList fields  = {"user_id","username","password","email","phone","role","created_at","updated_at"};
    m_model = new QStandardItemModel(users.size(),headers.size(),this);
    m_model->setHorizontalHeaderLabels(headers);
    for(int row=0; row<users.size(); ++row){
        const QVariantMap &user = users.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(user.value(key).toString());
            m_model->setItem(row,col,item);
        }
    }
    ui->tableView->setModel(m_model);

    connect(ui->btnDeleteUser,&QPushButton::clicked,this,&AdminController::deleteUser);
}

void AdminController::deleteUser()
{

}

AdminController::~AdminController()
{
    delete ui;
}
