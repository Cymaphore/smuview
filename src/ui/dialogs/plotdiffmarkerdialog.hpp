/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2018-2020 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UI_DIALOGS_PLOTDIFFMARKERDIALOG_HPP
#define UI_DIALOGS_PLOTDIFFMARKERDIALOG_HPP

#include <map>

#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QString>
#include <QWidget>

#include "src/ui/widgets/plot/plot.hpp"

namespace sv {
namespace ui {
namespace dialogs {

class PlotDiffMarkerDialog : public QDialog
{
	Q_OBJECT

public:
	explicit PlotDiffMarkerDialog(widgets::plot::Plot *plot,
		QWidget *parent = nullptr);

private:
	void setup_ui();

	widgets::plot::Plot *plot_;
	QComboBox *marker_1_combobox_;
	QComboBox *marker_2_combobox_;
	QDialogButtonBox *button_box_;

public Q_SLOTS:
	void accept() override;

};

} // namespace dialogs
} // namespace ui
} // namespace sv

#endif // UI_DIALOGS_PLOTDIFFMARKERDIALOG_HPP
