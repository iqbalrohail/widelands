/*
 * Copyright (C) 2002-2004, 2006-2013 by the Widelands Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef _SOLDIERCAPACITYCONTROL_H_
#define _SOLDIERCAPACITYCONTROL_H_

#include "ui_basic/box.h"
#include "ui_basic/button.h"
#include "ui_basic/textarea.h"

class Interactive_GameBase;


namespace Widelands {
class Garrison;
}
namespace UI {

/**
 * Widget to control the capacity of \ref MilitaryBuilding and \ref TrainingSite
 * via \ref SoldierControl
 */
struct SoldierCapacityControl : Box {
	SoldierCapacityControl
		(UI::Panel * parent, Interactive_GameBase & igb,
		 Widelands::Garrison & garrison);

protected:
	virtual void think();

private:
	void change_soldier_capacity(int delta);
	void click_decrease();
	void click_increase();

	Interactive_GameBase & m_igb;
	Widelands::Garrison & m_garrison;

	Button m_decrease;
	Button m_increase;
	Textarea m_value;
};

}

#endif // _SOLDIERLIST_H_
