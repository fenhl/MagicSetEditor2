//+----------------------------------------------------------------------------+
//| Description:  Magic Set Editor - Program to make Magic (tm) cards          |
//| Copyright:    (C) 2001 - 2006 Twan van Laarhoven                           |
//| License:      GNU General Public License 2 or later (see file COPYING)     |
//+----------------------------------------------------------------------------+

// ----------------------------------------------------------------------------- : Includes

#include <data/game.hpp>
#include <util/io/package_manager.hpp>

// ----------------------------------------------------------------------------- : Game

GameP Game::byName(const String& name) {
	return packages.open<Game>(name + _(".mse-game"));
}

bool Game::isMagic() const {
	return name() == _("magic");
}

String Game::typeName() const { return _("game"); }

IMPLEMENT_REFLECTION(Game) {
	REFLECT_N("full name", fullName);
	REFLECT_N("icon",      iconFilename);
}