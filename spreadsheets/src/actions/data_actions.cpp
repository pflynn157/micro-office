//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <iostream>

#include "data_actions.hpp"
#include "../tabwidget.hpp"
#include "../sheetwidget.hpp"
#include "../tablewidget.hpp"

DataItem DataActions::clipboard1;
QVector<DataItem> DataActions::clipboard;
bool DataActions::cut = false;

void DataActions::load_clipboard(bool cut_data) {
    cut = cut_data;
    SheetWidget *sheet = TabWidget::currentWidget();

    if (sheet->currentTable()->currentSelectedItems().size()==1) {
        QTableWidgetItem *current = sheet->currentCell();
        clipboard1.item.x = current->column();
        clipboard1.item.y = current->row();
        clipboard1.item.data = current->text();

        //TODO: Move this to its own function, probably in the table widget
        QString bgRole = current->data(Qt::BackgroundRole).toString();
        if (bgRole.isEmpty()) {
            clipboard1.item.bgColor = Qt::white;
        } else {
            clipboard1.item.bgColor = current->background().color();
        }
        clipboard1.item.fgColor = current->foreground().color();


        clipboard1.original_col = current->column();
        clipboard1.original_row = current->row();
    } else {
        auto items = sheet->currentTable()->currentSelectedItems();
        for (int i = 0; i<items.size(); i++) {
            auto current = items.at(i);
            DataItem item;
            item.original_col = current.column();
            item.original_row = current.row();
            
            QTableWidgetItem *tb_item = sheet->currentTable()->item(current.row(),current.column());
            if (tb_item==nullptr) {
              item.item.data = "";
              item.item.bgColor = Qt::white;
              item.item.fgColor = Qt::black;
            } else {
                item.item.data = tb_item->text();

                //TODO: Move this to its own function, probably in the table widget
                QString bgRole = tb_item->data(Qt::BackgroundRole).toString();
                if (bgRole.isEmpty()) {
                    item.item.bgColor = Qt::white;
                } else {
                    item.item.bgColor = tb_item->background().color();
                }
                item.item.fgColor = tb_item->foreground().color();
            }
            
            clipboard.push_back(item);
        }
    }
}

void DataActions::paste_data() {
    QTableWidgetItem *current = TabWidget::currentWidget()->currentCell();
    if (clipboard.isEmpty()) {
        paste_single_item(current->row(),current->column());
    } else {
        int cx = current->column();
        int cy = current->row();
        
        std::cout << "CX: " << cx << std::endl;
        std::cout << "CY: " << cy << std::endl << std::endl;
        
        int diff_x = 0;
        int diff_y = 0;
        int last_x = -1;
        int last_y = -1;
        
        for (DataItem item : clipboard) {
          int ox = item.original_col;
          int oy = item.original_row;
          std::cout << "O: " << ox << " " << oy << std::endl;
          
          if (last_x != -1 && last_y != -1) {
              diff_x = ox-last_x;
              diff_y = oy-last_y;
              
              if (diff_x<0) {
                diff_x*=-1;
              }
              
              if (diff_y<0) {
                diff_y*=-1;
              }
          }
          
          int dest_x = cx+diff_x;
          int dest_y = cy+diff_y;
          
          last_x = ox;
          last_y = oy;
          
          //Sets the new item
          QTableWidgetItem *nitem = TabWidget::currentWidget()->currentTable()->item(dest_x,dest_y);
          if (nitem==nullptr) {
              nitem = new QTableWidgetItem;
          }
          nitem->setText(item.item.data);
          nitem->setBackground(QBrush(item.item.bgColor));
          nitem->setForeground(QBrush(item.item.fgColor));
          TabWidget::currentWidget()->currentTable()->setItem(dest_y,dest_x,nitem);
          
          if (cut) {
              //Erases the old item
              QTableWidgetItem *original = TabWidget::currentWidget()->currentTable()->item(oy,ox);
              original = new QTableWidgetItem;
              TabWidget::currentWidget()->currentTable()->setItem(oy,ox,original);
          }
          
          diff_x = 0;
          diff_y = 0;
        }
        
        clipboard.clear();
    }
}

void DataActions::paste_single_item(int dest_row, int dest_col) {
    TableWidget *current = TabWidget::currentWidget()->currentTable();
    QTableWidgetItem *item = current->item(dest_row,dest_col);
    if (item==nullptr) {
        item = new QTableWidgetItem;
    }

    item->setText(clipboard1.item.data);
    item->setBackground(QBrush(clipboard1.item.bgColor));
    item->setForeground(QBrush(clipboard1.item.fgColor));
    current->setItem(dest_row,dest_col,item);

    if (cut) {
        QTableWidgetItem *original = new QTableWidgetItem;
        current->setItem(clipboard1.original_row,clipboard1.original_col,original);
    }
}
