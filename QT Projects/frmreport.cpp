#include "frmreport.h"
#include "ui_frmreport.h"
#include <string>
frmReport::frmReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmReport)
{
    ui->setupUi(this);
    ppkm = new party_pkm();
    pkm = new pokemon_obj();
    pview_ = new pkmviewer();
    sqlite3_open(":memory:", &db);
    createtable();
}
extern void * theSlot;
extern int frmCurBoxNum;
extern bw2savblock_obj * cursavblock;
extern int frmCurSlotNum;
std::string TableName;
vector<std::string> POSValues;
vector<std::string> positions;
void frmReport::createtable()
{
    /*
    TODO: Add columns to the data table:
    Shiny
    Pokérus
    Moves
    Ability
    Item
    Gender
    Tameness
    Types
    IVs
    EVs
    Form
    Original game
    OT name (set color for gender)
    OT ID / SID
    Nature
    Nickname
    Level
    Markings
    Fateful
    N's
    Country
    Pokéstar shine
    # of ribbons
    */
    vector<std::string> ColumnNames;
    // Add column names here
    ColumnNames.push_back("No.");
    ColumnNames.push_back("Species");
    ColumnNames.push_back("HP");
    ColumnNames.push_back("Attack");
    ColumnNames.push_back("Defense");
    ColumnNames.push_back("Sp. Attack");
    ColumnNames.push_back("Sp. Defense");
    ColumnNames.push_back("Speed");
    ColumnNames.push_back("Shiny");
    ColumnNames.push_back("Pokérus");
    ColumnNames.push_back("Move 1");
    ColumnNames.push_back("Move 2");
    ColumnNames.push_back("Move 3");
    ColumnNames.push_back("Move 4");
    ColumnNames.push_back("Ability");
    ColumnNames.push_back("Item");
    ColumnNames.push_back("Gender");
    ColumnNames.push_back("Tameness");
    ColumnNames.push_back("Type 1");
    ColumnNames.push_back("Type 2");
    ColumnNames.push_back("HP IV");
    ColumnNames.push_back("Atk IV");
    ColumnNames.push_back("Def IV");
    ColumnNames.push_back("SpAtk IV");
    ColumnNames.push_back("SpDef IV");
    ColumnNames.push_back("Speed IV");
    ColumnNames.push_back("HP EV");
    ColumnNames.push_back("Atk EV");
    ColumnNames.push_back("Def EV");
    ColumnNames.push_back("SpAtk EV");
    ColumnNames.push_back("SpDef EV");
    ColumnNames.push_back("Speed EV");
    ColumnNames.push_back("Form");
    ColumnNames.push_back("Game");
    ColumnNames.push_back("OT");
    ColumnNames.push_back("TID");
    ColumnNames.push_back("SID");
    ColumnNames.push_back("Nature");
    ColumnNames.push_back("Nickname");
    ColumnNames.push_back("Level");
    ColumnNames.push_back("Fateful");
    ColumnNames.push_back("N's PKM");
    ColumnNames.push_back("Country");
    ColumnNames.push_back("Pokéstar");
    ColumnNames.push_back("Ribbons");
    ColumnNames.push_back("Circle");
    ColumnNames.push_back("Square");
    ColumnNames.push_back("Heart");
    ColumnNames.push_back("Triangle");
    ColumnNames.push_back("Star");
    ColumnNames.push_back("Diamond");
    // Leave Position for last
    ColumnNames.push_back("Position");
    vector<std::string> ColumnTypes;
    // Add column data types here
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("Integer");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    ColumnTypes.push_back("String");
    // Leave Position for last
    ColumnTypes.push_back("String");
    // Add vectors for column data here
    vector<int> IDValues;
    vector<std::string> SpeciesNames;
    vector<int> HPValues;
    vector<int> AtkValues;
    vector<int> DefValues;
    vector<int> SpAtkValues;
    vector<int> SpDefValues;
    vector<int> SpeedValues;
    vector<std::string> ShinyValues;
    vector<std::string> PKRSValues;
    vector<std::string> Move1Values;
    vector<std::string> Move2Values;
    vector<std::string> Move3Values;
    vector<std::string> Move4Values;
    vector<std::string> AbilityValues;
    vector<std::string> ItemValues;
    vector<std::string> GenderValues;
    vector<std::string> TamenessValues;
    vector<std::string> Type1Values;
    vector<std::string> Type2Values;
    vector<int> HPIVValues;
    vector<int> AtkIVValues;
    vector<int> DefIVValues;
    vector<int> SpAtkIVValues;
    vector<int> SpDefIVValues;
    vector<int> SpeedIVValues;
    vector<int> HPIVValues;
    vector<int> AtkIVValues;
    vector<int> DefIVValues;
    vector<int> SpAtkIVValues;
    vector<int> SpDefIVValues;
    vector<int> SpeedEVValues;
    vector<std::string> FormValues;
    vector<std::string> GameValues;
    vector<std::string> OTValues;
    vector<std::string> TIDValues;
    vector<std::string> SIDValues;
    vector<std::string> NatureValues;
    vector<std::string> NicknameValues;
    vector<int> LevelValues;
    vector<std::string> FatefulValues;
    vector<std::string> NValues;
    vector<std::string> CountryValues;
    vector<std::string> PokestarValues;
    vector<int> RibbonValues;
    vector<std::string> CircleValues;
    vector<std::string> SquareValues;
    vector<std::string> HeartValues;
    vector<std::string> TriangleValues;
    vector<std::string> StarValues;
    vector<std::string> DiamondValues;
    POSValues.clear();
    //    int box = 0;
    for(int box = 0; box < 24; box++)
    {
        for(int slot = 0; slot < 30; slot++)
        {
            pkm = &(cursavblock->boxes[box].pokemon[slot]);
            if(!((bool)(pkm->isboxdatadecrypted)))
            {
                decryptpkm(pkm);
            }
            if(pkm->species != Species::NOTHING)
            {
                // Add values to vectors here
                IDValues.push_back((int)(pkm->species));
                SpeciesNames.push_back(lookuppkmname(pkm));
                HPValues.push_back(getpkmstat(pkm,Stat_IDs::hp));
                AtkValues.push_back(getpkmstat(pkm,Stat_IDs::attack));
                DefValues.push_back(getpkmstat(pkm,Stat_IDs::defense));
                SpAtkValues.push_back(getpkmstat(pkm,Stat_IDs::spatk));
                SpDefValues.push_back(getpkmstat(pkm,Stat_IDs::spdef));
                SpeedValues.push_back(getpkmstat(pkm,Stat_IDs::speed));
                ShinyValues.push_back();
                PKRSValues.push_back();
                Move1Values.push_back();
                Move2Values.push_back();
                Move3Values.push_back();
                Move4Values.push_back();
                AbilityValues.push_back();
                ItemValues.push_back();
                GenderValues.push_back();
                TamenessValues.push_back();
                Type1Values.push_back();
                Type2Values.push_back();
                HPIVValues.push_back();
                AtkIVValues.push_back();
                DefIVValues.push_back();
                SpAtkIVValues.push_back();
                SpDefIVValues.push_back();
                SpeedIVValues.push_back();
                HPIVValues.push_back();
                AtkIVValues.push_back();
                DefIVValues.push_back();
                SpAtkIVValues.push_back();
                SpDefIVValues.push_back();
                SpeedEVValues.push_back();
                FormValues.push_back();
                GameValues.push_back();
                OTValues.push_back();
                TIDValues.push_back();
                SIDValues.push_back();
                NatureValues.push_back();
                NicknameValues.push_back();
                LevelValues.push_back();
                FatefulValues.push_back();
                NValues.push_back();
                CountryValues.push_back();
                PokestarValues.push_back();
                RibbonValues.push_back();
                CircleValues.push_back();
                SquareValues.push_back();
                HeartValues.push_back();
                TriangleValues.push_back();
                StarValues.push_back();
                DiamondValues.push_back();
                std::ostringstream position;
                position << box << "," << slot;
                POSValues.push_back(position.str());
            }
        }
    }
    TableName = "PKM_DATA";
    stringstream ss1;
    ss1 << "create table " << TableName << "(";
    for(int i = 0; i < ColumnNames.size()-1; i++)
    {
        ss1 << "\"" << ColumnNames[i] << "\"" << " " << ColumnTypes[i] << ", ";
    }
    ss1 << "\"" << ColumnNames[ColumnNames.size()-1] << "\"" << " " << ColumnTypes[ColumnNames.size()-1];
    ss1 << ")";
    sqlite3_prepare_v2(db,ss1.str().c_str(),-1,&stmt,0);
    sqlite3_step(stmt);
    stringstream ss2;
    ss2 << "insert into " << TableName << "(";
    for(int i = 0; i < ColumnNames.size()-1; i++)
    {
        ss2 << "\"" << ColumnNames[i] << "\"" << ", ";
    }
    ss2 << ColumnNames[ColumnNames.size()-1];
    ss2 << ") values ";
    for(int p = 0; p < SpeciesNames.size()-1; p++)
    {
        // Get data from vectors here
        ss2 << "(";
        ss2 << IDValues[p] << ", ";
        ss2 << "\"" << SpeciesNames[p] << "\", ";
        ss2 << HPValues[p] << ", ";
        ss2 << AtkValues[p] << ", ";
        ss2 << DefValues[p] << ", ";
        ss2 << SpAtkValues[p] << ", ";
        ss2 << SpDefValues[p] << ", ";
        ss2 << SpeedValues[p] << ", ";
        
        ss2 << "\"" << POSValues[p] << "\"";
        ss2 << "),\n";
    }
    int p = (int)(SpeciesNames.size())-1;
    // Get data from vectors here
    ss2 << "(";
    ss2 << IDValues[p] << ", ";
    ss2 << "\"" << SpeciesNames[p] << "\", ";
    ss2 << HPValues[p] << ", ";
    ss2 << AtkValues[p] << ", ";
    ss2 << DefValues[p] << ", ";
    ss2 << SpAtkValues[p] << ", ";
    ss2 << SpDefValues[p] << ", ";
    ss2 << SpeedValues[p] << ", ";
    
    ss2 << "\"" << POSValues[p] << "\"";
    ss2 << ");";
    sqlite3_prepare_v2(db,ss2.str().c_str(),-1,&stmt,0);
    sqlite3_step(stmt);
    for(int i = 0; i < ColumnNames.size(); i++)
    {
        if(ColumnNames[i] != "Position")
        {
            ui->lstColumns->addItem(QString::fromStdString(ColumnNames[i]));
        }
    }
}
frmReport::~frmReport()
{
    sqlite3_close(db);
    delete ui;
}
void frmReport::dosearch(vector<std::string> columns, string where, string order, int limit)
{
    std::ostringstream query;
    query << "SELECT ";
    for(int i = 0; i < columns.size() - 1; i++)
    {
        query << "\"" << columns[i] << "\", ";
    }
    query << "\"" << columns[columns.size()-1] << "\", \"Position";
    query << "\" FROM " << TableName;
    if(where != "")
    {
        query << " WHERE " << where;
    }
    if(order != "")
    {
        query << " ORDER BY " << order;
    }
    if(limit != 0)
    {
        query << " LIMIT " << limit;
    }
    vector<vector<string> > results;
    if(sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, 0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(stmt);
        int result = 0;
        while(true)
        {
            result = sqlite3_step(stmt);
            if(result == SQLITE_ROW)
            {
                vector<string> values;
                for(int col = 0; col < cols; col++)
                {
                    values.push_back((char*)sqlite3_column_text(stmt, col));
                }
                results.push_back(values);
            }
            else
            {
                break;
            }
        }
        sqlite3_finalize(stmt);
    }
    QVector<QString> vect;
    for(int i = 0; i < columns.size(); i++)
    {
        std::ostringstream o;
        o << columns[i];
        vect.push_back(QString::fromStdString(o.str()));
    }
    ui->tblPKM->setHorizontalHeaderLabels(QStringList::fromVector(vect));
    int c = 0;
    for(vector<vector<string> >::iterator it = results.begin(); it < results.end(); ++it)
    {
        vector<string> row = *it;
        ui->tblPKM->insertRow(ui->tblPKM->rowCount());
        positions.push_back(POSValues[c]);
        for(int i = 0; i < columns.size(); i++)
        {
            ui->tblPKM->setItem(ui->tblPKM->rowCount()-1,i,new QTableWidgetItem(tr(QString::fromStdString(row.at(i)).toLatin1())));
        }
        c++;
    }
}
void frmReport::on_btnSearch_clicked()
{
    ui->tblPKM->setRowCount(0);
    ui->tblPKM->setColumnCount(0);
    if(ui->lstColumns->selectedItems().count() > 0)
    {
        vector<string> columns;
        QList<QListWidgetItem*> list = ui->lstColumns->selectedItems();
        for(int i= 0; i < list.count(); i++)
        {
            columns.push_back(list.at(i)->text().toStdString());
        }
        ui->tblPKM->setColumnCount(columns.size());
        dosearch(
                    columns
                    //                ,"ID <= 150"
                    //                ,""
                    //                ,"Attack ASC"
                    //                ,""
                    //                ,100
                    );
    }
}
void frmReport::on_tblPKM_cellDoubleClicked(int row, int column)
{
    std::vector<std::string> pos = split(positions[row],',');
    pkm = &(cursavblock->boxes[QString::fromStdString(pos[0]).toInt()].pokemon[QString::fromStdString(pos[1]).toInt()]);
    pview_->setPKM(pkm,frmCurBoxNum, false);
    pview_->displayPKM();
    pview_->show();
}