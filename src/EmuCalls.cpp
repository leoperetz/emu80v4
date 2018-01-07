/*
 *  Emu80 v. 4.x
 *  © Viktor Pykhonin <pyk@mail.ru>, 2018
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Emulation core rouninues to be called from platform abstraction layer (PAL)


#include "Emulation.h"
#include "EmuWindow.h"

using namespace std;


// Keyboard event
void emuKeyboard(PalWindow* wnd, PalKeyCode key, bool isPressed)
{
    g_emulation->processKey(static_cast<EmuWindow*>(wnd), key, isPressed);
}


// System request
void emuSysReq(PalWindow* wnd, SysReq sr)
{
    g_emulation->sysReq(static_cast<EmuWindow*>(wnd), sr);
}


// Active window changed
void emuFocusWnd(PalWindow* wnd)
{
    g_emulation->setWndFocus(static_cast<EmuWindow*>(wnd));
}


// Drop files event
void emuDropFile(PalWindow* wnd, char* fileName)
{
    g_emulation->dropFile(static_cast<EmuWindow*>(wnd), std::string(fileName));
}


// Main emulation procedure
void emuEmulationCycle()
{
    g_emulation->mainLoopCycle();
}


// Set emulation object's single property value
bool emuSetPropertyValue(const string& objName, const string& propName, const string& value)
{
    EmuObject* obj = g_emulation->findObject(objName);
    if (!obj)
        return false;
    return obj->setProperty(propName, value);
}


// Get emulation object's property string value
string emuGetPropertyValue(const string& objName, const string& propName)
{
    EmuObject* obj = g_emulation->findObject(objName);
    return obj->getPropertyStringValue(propName);
}