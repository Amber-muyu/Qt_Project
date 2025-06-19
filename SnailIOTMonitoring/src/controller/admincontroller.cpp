#include "admincontroller.h"
#include "ui_admincontroller.h"

#include <QMessageBox>

AdminController::AdminController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminController)
{
    ui->setupUi(this);
    ui->lineEditSelectUser->setClearButtonEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    UserManager &userManager = UserManager::instance();
    QList<QVariantMap> users = userManager.getAllUsers();

    initUserInfoPage(users);
    autoRefresh();

    connect(ui->lineEditSelectUser,&QLineEdit::textChanged,this,[=](const QString &text){

        m_isSearching = !text.trimmed().isEmpty();
        UserManager &userManager = UserManager::instance();
        QList<QVariantMap> users;
        if (text.trimmed().isEmpty()) {
            users = userManager.getAllUsers();
        } else {
            users = userManager.searchUsers(text.trimmed());
        }
        initUserInfoPage(users);
    });

    connect(ui->btnAddUser,&QPushButton::clicked,this,&AdminController::addUser);
    connect(ui->btnModifyUser,&QPushButton::clicked,this,&AdminController::modifyUser);
    connect(ui->btnDeleteUser,&QPushButton::clicked,this,&AdminController::deleteUser);
}

void AdminController::initUserInfoPage(const QList<QVariantMap>& users)
{

    QStringList headers = {"序号","用户名","密码","邮箱","电话","角色","注册时间","更新时间"};
    QStringList fields  = {"user_id","username","password","email","phone","role","created_at","updated_at"};

    if (!m_model) {
        m_model = new QStandardItemModel(this);
        ui->tableView->setModel(m_model);             // 只setModel 一次
    }

    m_model->clear();
    m_model->setRowCount(users.size());
    m_model->setColumnCount(headers.size());
    m_model->setHorizontalHeaderLabels(headers);

    for(int row=0; row<users.size(); ++row){
        const QVariantMap &user = users.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(user.value(key).toString());
            m_model->setItem(row,col,item);
        }
    }
}

void AdminController::autoRefresh()
{
    QTimer *timer = new QTimer(this);  // this确保随窗口销毁
    connect(timer, &QTimer::timeout, this,[=](){
        if (!m_isSearching) {
            UserManager &userManager = UserManager::instance();
            QList<QVariantMap> users = userManager.getAllUsers();
            initUserInfoPage(users);
        }
    });
    timer->start(10000);  // 每10秒刷新一次
}

void AdminController::addUser()
{
    m_adminUserInfoAdd = new AdminUserInfoAdd;
    m_adminUserInfoAdd->setAttribute(Qt::WA_ShowModal);

    connect(m_adminUserInfoAdd,&AdminUserInfoAdd::addFinish,this,[=](){
        UserManager &userManager = UserManager::instance();
        QList<QVariantMap> users = userManager.getAllUsers();
        initUserInfoPage(users);
    });

    m_adminUserInfoAdd->show();
}

void AdminController::modifyUser()
{
    m_adminUserInfoModify = new AdminUserInfoModify;
    m_adminUserInfoModify->setAttribute(Qt::WA_ShowModal);

    int modifyRow = ui->tableView->currentIndex().row();
    if(modifyRow<0){
        QMessageBox::warning(this,"信息","未选中无法修改");
        return;
    }else {
        int modifyUserId = m_model->item(modifyRow,0)->text().toInt();
        connect(this,&AdminController::sendModifyUserInfo,m_adminUserInfoModify,&AdminUserInfoModify::modifyByUserId);
        emit sendModifyUserInfo(modifyUserId);
    }

    connect(m_adminUserInfoModify,&AdminUserInfoModify::modifyFinish,this,[=](){
        UserManager &userManager = UserManager::instance();
        QList<QVariantMap> users = userManager.getAllUsers();
        initUserInfoPage(users);
    });

    m_adminUserInfoModify->show();
}

void AdminController::deleteUser()
{
    int deleteRow = ui->tableView->currentIndex().row();
    if(deleteRow<0){
        QMessageBox::warning(this,"提示","未选中无法删除");
        return;
    }
    QString userName = m_model->item(deleteRow,1)->text();
    int ret = QMessageBox::question(
                this,
                "确认删除",
                QString("确定要删除用户 %1 吗？").arg(userName),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No
                );
    if (ret == QMessageBox::Yes) {
        int deleteId = m_model->item(deleteRow,0)->text().toInt();
        UserManager &userManager = UserManager::instance();
        if(userManager.deleteUser(deleteId)){
            QMessageBox::information(this,"信息","删除成功");
            QList<QVariantMap> users = userManager.getAllUsers();
            initUserInfoPage(users);
        }else {
            QMessageBox::warning(this,"失败","删除失败");
        }
    }
}

AdminController::~AdminController()
{
    delete ui;
}
