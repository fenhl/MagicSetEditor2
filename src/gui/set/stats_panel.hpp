//+----------------------------------------------------------------------------+
//| Description:  Magic Set Editor - Program to make Magic (tm) cards          |
//| Copyright:    (C) Twan van Laarhoven and the other MSE developers          |
//| License:      GNU General Public License 2 or later (see file COPYING)     |
//+----------------------------------------------------------------------------+

#pragma once

// ----------------------------------------------------------------------------- : Includes

#include <util/prec.hpp>
#include <gui/set/panel.hpp>
#include <data/graph_type.hpp>

class StatCategoryList;
class StatDimensionList;
class GraphControl;
class FilteredCardList;

// Pick the style here:
#define USE_DIMENSION_LISTS 1
#define USE_SEPARATE_DIMENSION_LISTS 0

// ----------------------------------------------------------------------------- : StatsPanel

/// A panel for showing statistics on cards
class StatsPanel : public SetWindowPanel {
public:
  StatsPanel(Window* parent, int id);
  ~StatsPanel();
  
  // --------------------------------------------------- : UI
  
  void onChangeSet() override;
  void onAction(const Action&, bool undone) override;
  
  void initUI   (wxToolBar*, wxMenuBar*) override;
  void destroyUI(wxToolBar*, wxMenuBar*) override;
  void onUpdateUI(wxUpdateUIEvent&) override;
  void onCommand(int id) override;
  
  // --------------------------------------------------- : Selection
  CardP selectedCard() const override;
  void selectCard(const CardP& card) override;
  
  // --------------------------------------------------- : Data
private:
  DECLARE_EVENT_TABLE();
  
  #if USE_SEPARATE_DIMENSION_LISTS
    StatDimensionList* dimensions[3];
  #elif USE_DIMENSION_LISTS
    StatDimensionList* dimensions;
  #else
    StatCategoryList* categories;
  #endif
  GraphControl*     graph;
  FilteredCardList* card_list;
  wxMenu*           menuGraph;
  
  CardP card;      ///< Selected card
  bool up_to_date; ///< Are the graph and card list up to date?
  bool active;     ///< Is this panel selected?
  
  void initControls();
  
  void onChange();
  void onGraphSelect(wxCommandEvent&);
  void showCategory(const GraphType* prefer_layout = nullptr);
  void showLayout(GraphType);
  void filterCards();
};

