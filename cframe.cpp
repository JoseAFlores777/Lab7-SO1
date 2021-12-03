#include "cframe.h"
#include "ui_cframe.h"

CFrame::CFrame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CFrame)
{

    disponiblesSize=5;
    PAltaSize=1;
    PMediaSize=1;
    PBajaSize=1;
    ui->setupUi(this);
    Predefinido();
    MostrarDisponibles();
    on_tabWidget_Listas_tabBarClicked(0);


}

CFrame::~CFrame()
{
    delete ui;
}

void CFrame::Predefinido()
{
    L.insertarAlFinal( new Vehiculo(("Veh-001"),"Toyota","Hilux","Rojo Metalico",2001,255000,"2.8 Diesel","4x4 Trasera",400000) );
    L.insertarAlFinal( new Vehiculo(("Veh-002"),"Mazda","BT50","Verde Metalico",2015,50000,"2.5 Diesel","4x4 Trasera",350000) );
    L.insertarAlFinal( new Vehiculo(("Veh-003"),"Toyota","22R","Gris Metalico",1986,450000,"V4 Gasolina","4x4 Trasera",250000) );
    L.insertarAlFinal( new Vehiculo(("Veh-004"),"Jeep","Cherokee","Gris",2008,125000,"2.8 Diesel","4x4 Trasera",300000) );
    L.insertarAlFinal( new Vehiculo(("Veh-005"),"Suzuki","Jimny","Verde 2 Tonos",2019,50000,"1.5 Gasolina","4x4 Trasera",360000) );
}

int CFrame::ContarDisponibles()
{
    int C = 0;

    ActP = L.primeroPtr;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}

int CFrame::ContarPAlta()
{
    int C = 0;

    ActP = ColaPAlta.PrimP;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}

int CFrame::ContarPMedia()
{
    int C = 0;

    ActP = ColaPMedia.PrimP;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}

int CFrame::ContarPBaja()
{
    int C = 0;

    ActP = ColaBaja.PrimP;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}




void CFrame::MostrarDisponibles()
{
tabPermission(1);
    ui->tableWidget_disponibles->clear();

    ui->tableWidget_disponibles->setColumnCount(10);
    ui->tableWidget_disponibles->setRowCount( ContarDisponibles() );

    ui->tableWidget_disponibles->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Marca"<<"Modelo"<<"Color"<<"Año"<<"Recorrido"<<"Motor"<<"Tracción"<<"Precio" );

    int P=0;
    disponiblesSize = 0;
    for ( ActP=L.primeroPtr ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        disponiblesSize ++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Mar = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMarca() ) );
        QTableWidgetItem *Mod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getModelo() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Ani = new QTableWidgetItem( QString::number( ActP->datos->getAnio() ) );
        QTableWidgetItem *Rec = new QTableWidgetItem( QString::number( ActP->datos->getRecorrido() ) );
        QTableWidgetItem *Mot = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMotor() ) );
        QTableWidgetItem *Tra = new QTableWidgetItem( QString::fromStdString( ActP->datos->getTraccion() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );

        ui->tableWidget_disponibles->setItem(P,0,Pos);
        ui->tableWidget_disponibles->setItem(P,1,Cod);
        ui->tableWidget_disponibles->setItem(P,2,Mar);
        ui->tableWidget_disponibles->setItem(P,3,Mod);
        ui->tableWidget_disponibles->setItem(P,4,Col);
        ui->tableWidget_disponibles->setItem(P,5,Ani);
        ui->tableWidget_disponibles->setItem(P,6,Rec);
        ui->tableWidget_disponibles->setItem(P,7,Mot);
        ui->tableWidget_disponibles->setItem(P,8,Tra);
        ui->tableWidget_disponibles->setItem(P,9,Pre);
    }
}

void CFrame::MostrarPAlta()
{
    ui->tableWidget_PAlta->clear();

    ui->tableWidget_PAlta->setColumnCount(10);
    ui->tableWidget_PAlta->setRowCount( ContarPAlta() );

    ui->tableWidget_PAlta->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Marca"<<"Modelo"<<"Color"<<"Año"<<"Recorrido"<<"Motor"<<"Tracción"<<"Precio" );

    int P=0;
    PAltaSize =0;
    for ( ActP=ColaPAlta.PrimP ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        PAltaSize++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Mar = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMarca() ) );
        QTableWidgetItem *Mod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getModelo() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Ani = new QTableWidgetItem( QString::number( ActP->datos->getAnio() ) );
        QTableWidgetItem *Rec = new QTableWidgetItem( QString::number( ActP->datos->getRecorrido() ) );
        QTableWidgetItem *Mot = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMotor() ) );
        QTableWidgetItem *Tra = new QTableWidgetItem( QString::fromStdString( ActP->datos->getTraccion() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );

        ui->tableWidget_PAlta->setItem(P,0,Pos);
        ui->tableWidget_PAlta->setItem(P,1,Cod);
        ui->tableWidget_PAlta->setItem(P,2,Mar);
        ui->tableWidget_PAlta->setItem(P,3,Mod);
        ui->tableWidget_PAlta->setItem(P,4,Col);
        ui->tableWidget_PAlta->setItem(P,5,Ani);
        ui->tableWidget_PAlta->setItem(P,6,Rec);
        ui->tableWidget_PAlta->setItem(P,7,Mot);
        ui->tableWidget_PAlta->setItem(P,8,Tra);
        ui->tableWidget_PAlta->setItem(P,9,Pre);
    }
}

void CFrame::MostrarPMedia()
{
    ui->tableWidget_PMedia->clear();

    ui->tableWidget_PMedia->setColumnCount(10);
    ui->tableWidget_PMedia->setRowCount( ContarPMedia() );

    ui->tableWidget_PMedia->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Marca"<<"Modelo"<<"Color"<<"Año"<<"Recorrido"<<"Motor"<<"Tracción"<<"Precio" );

    int P=0;
    PMediaSize =0;
    for ( ActP=ColaPMedia.PrimP ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        PMediaSize++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Mar = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMarca() ) );
        QTableWidgetItem *Mod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getModelo() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Ani = new QTableWidgetItem( QString::number( ActP->datos->getAnio() ) );
        QTableWidgetItem *Rec = new QTableWidgetItem( QString::number( ActP->datos->getRecorrido() ) );
        QTableWidgetItem *Mot = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMotor() ) );
        QTableWidgetItem *Tra = new QTableWidgetItem( QString::fromStdString( ActP->datos->getTraccion() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );

        ui->tableWidget_PMedia->setItem(P,0,Pos);
        ui->tableWidget_PMedia->setItem(P,1,Cod);
        ui->tableWidget_PMedia->setItem(P,2,Mar);
        ui->tableWidget_PMedia->setItem(P,3,Mod);
        ui->tableWidget_PMedia->setItem(P,4,Col);
        ui->tableWidget_PMedia->setItem(P,5,Ani);
        ui->tableWidget_PMedia->setItem(P,6,Rec);
        ui->tableWidget_PMedia->setItem(P,7,Mot);
        ui->tableWidget_PMedia->setItem(P,8,Tra);
        ui->tableWidget_PMedia->setItem(P,9,Pre);
    }
}

void CFrame::MostrarPBaja()
{
    ui->tableWidget_PBaja->clear();

    ui->tableWidget_PBaja->setColumnCount(10);
    ui->tableWidget_PBaja->setRowCount( ContarPBaja() );

    ui->tableWidget_PBaja->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Marca"<<"Modelo"<<"Color"<<"Año"<<"Recorrido"<<"Motor"<<"Tracción"<<"Precio" );

    int P=0;
    PBajaSize =0;
    for ( ActP=ColaBaja.PrimP ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        PBajaSize++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Mar = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMarca() ) );
        QTableWidgetItem *Mod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getModelo() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Ani = new QTableWidgetItem( QString::number( ActP->datos->getAnio() ) );
        QTableWidgetItem *Rec = new QTableWidgetItem( QString::number( ActP->datos->getRecorrido() ) );
        QTableWidgetItem *Mot = new QTableWidgetItem( QString::fromStdString( ActP->datos->getMotor() ) );
        QTableWidgetItem *Tra = new QTableWidgetItem( QString::fromStdString( ActP->datos->getTraccion() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );

        ui->tableWidget_PBaja->setItem(P,0,Pos);
        ui->tableWidget_PBaja->setItem(P,1,Cod);
        ui->tableWidget_PBaja->setItem(P,2,Mar);
        ui->tableWidget_PBaja->setItem(P,3,Mod);
        ui->tableWidget_PBaja->setItem(P,4,Col);
        ui->tableWidget_PBaja->setItem(P,5,Ani);
        ui->tableWidget_PBaja->setItem(P,6,Rec);
        ui->tableWidget_PBaja->setItem(P,7,Mot);
        ui->tableWidget_PBaja->setItem(P,8,Tra);
        ui->tableWidget_PBaja->setItem(P,9,Pre);
    }
}



void CFrame::on_tabWidget_priority_type_tabBarClicked(int index)
{
    switch (index) {
    case 0:
        ui->label_Title_tabla->setText("Prioridad Alta");
        MostrarPAlta();
        break;
    case 1:
        ui->label_Title_tabla->setText("Prioridad Media");
        MostrarPMedia();
        break;
    case 2:
        ui->label_Title_tabla->setText("Prioridad Baja");
        MostrarPBaja();
        break;
    }
    ui->spinBox_Vender->setValue(0);
}


void CFrame::on_tabWidget_Listas_tabBarClicked(int index)
{
    ui->spinBox_Mover->setValue(0);
    ui->spinBox_Vender->setValue(0);
    switch (index) {
    case 0:
        ui->label_Title_tabla->setText("Vehículos Disponibles");

        MostrarDisponibles();
        tabPermission(1);
        break;
    case 1:

        on_tabWidget_priority_type_tabBarClicked(0);
        tabPermission(2);
        break;
    }


}


void CFrame::tabPermission (int permissionType)
{
    switch (permissionType) {
        case 1:
        ui->pBtn_Mover->setEnabled(true);
        ui->spinBox_Mover->setEnabled(true);
        ui->pBtn_Vender->setEnabled(false);
        ui->pBtn_Agregar_2->setEnabled(true);
        ui->spinBox_Vender->setEnabled(false);
        ui->label_Pos_aVender->setEnabled(false);
        ui->label_Pos_aMover->setEnabled(true);
        break;

        case 2:
        ui->pBtn_Mover->setEnabled(false);
        ui->spinBox_Mover->setEnabled(false);
        ui->pBtn_Vender->setEnabled(true);
        ui->pBtn_Agregar_2->setEnabled(false);
        ui->spinBox_Vender->setEnabled(true);
        ui->label_Pos_aVender->setEnabled(true);
        ui->label_Pos_aMover->setEnabled(false);
        break;
    }
}



void CFrame::on_spinBox_Mover_valueChanged(int arg1)
{
    int tam_validate;
    if (ui->label_Title_tabla->text() == "Vehículos Disponibles") {
        tam_validate=disponiblesSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Alta"){
        tam_validate=PAltaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Media"){
        tam_validate=PMediaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Baja"){
        tam_validate=PBajaSize;
    }

    if (arg1>tam_validate-1) {

        ui->spinBox_Mover->setValue(arg1-1);
    }

}


void CFrame::on_spinBox_Vender_valueChanged(int arg1)
{
    int tam_validate;
    if (ui->label_Title_tabla->text() == "Vehículos Disponibles") {
        tam_validate=disponiblesSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Alta"){
        tam_validate=PAltaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Media"){
        tam_validate=PMediaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Baja"){
        tam_validate=PBajaSize;
    }

    if (arg1>tam_validate-1) {

        ui->spinBox_Vender->setValue(arg1-1);
    }
}


void CFrame::on_pBtn_Mover_clicked()
{

    int index = ui->spinBox_Mover->value();

Vehiculo* tmp = L.eliminarDeCualquier(index);
tmp->Imprimir();

if (tmp->getAnio() < 2010 ) {
    ColaPAlta.insertarAlFinal(tmp);
}else if((tmp->getAnio() >= 2010) && (tmp->getAnio()<=2015)){
    ColaPMedia.insertarAlFinal(tmp);
}else if(tmp->getAnio() > 2015){
    ColaBaja.insertarAlFinal(tmp);
}

MostrarDisponibles();

ui->spinBox_Mover->setValue(0);

}




void CFrame::on_pBtn_Vender_clicked()
{
    int index = ui->spinBox_Vender->value();

    if(ui->label_Title_tabla->text()=="Prioridad Alta"){
        Vehiculo* tmp = ColaPAlta.eliminarDeCualquier(index);
        L.insertarAlFinal(tmp);
        MostrarPAlta();
    }else if(ui->label_Title_tabla->text()=="Prioridad Media"){
        Vehiculo* tmp = ColaPMedia.eliminarDeCualquier(index);
        L.insertarAlFinal(tmp);
        MostrarPMedia();
    }else if(ui->label_Title_tabla->text()=="Prioridad Baja"){
        Vehiculo* tmp = ColaBaja.eliminarDeCualquier(index);
        L.insertarAlFinal(tmp);
        MostrarPBaja();
    }

ui->spinBox_Vender->setValue(0);
}


void CFrame::on_pBtn_Agregar_2_clicked()
{
    Vehiculo* tmp = new Vehiculo();
    tmp->Leer();
    L.insertarAlFinal(tmp);
}

