/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2017-2020 Frank Stettner <frank-stettner@gmx.net>
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

#ifndef UI_DIALOGS_SAVEDIALOG_HPP
#define UI_DIALOGS_SAVEDIALOG_HPP

#include <memory>
#include <vector>

#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QString>
#include <QTreeWidget>

#include "src/session.hpp"

using std::shared_ptr;
using std::vector;

namespace sv {

namespace devices {
class BaseDevice;
}

namespace ui {

namespace devices {
namespace devicetree {
class DeviceTreeView;
}
}

namespace dialogs {

class SaveDialog : public QDialog
{
	Q_OBJECT

public:
	SaveDialog(const Session &session,
		const shared_ptr<sv::devices::BaseDevice> selected_device,
		QWidget *parent = nullptr);

private:
	void setup_ui();
	void save(const QString &file_name);
	void save_combined(const QString &file_name, const double combined_timeframe = 0);

	const Session &session_;
	const shared_ptr<sv::devices::BaseDevice> selected_device_;

	ui::devices::devicetree::DeviceTreeView *device_tree_;
	QCheckBox *timestamps_combined_;
	QLineEdit *timestamps_combined_timeframe_;
	QCheckBox *time_absolut_;
	QLineEdit *separator_edit_;
	QDialogButtonBox *button_box_;

public Q_SLOTS:
	void accept() override;
	void toggle_combined(int state);

};

} // namespace dialogs
} // namespace ui
} // namespace sv

#endif // UI_DIALOGS_SAVEDIALOG_HPP
