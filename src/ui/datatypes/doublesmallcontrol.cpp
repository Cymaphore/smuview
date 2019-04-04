/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2019 Frank Stettner <frank-stettner@gmx.net>
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

#include <QDebug>
#include <QVBoxLayout>

#include "doublesmallcontrol.hpp"
#include "src/devices/properties/baseproperty.hpp"
#include "src/ui/datatypes/doubleknob.hpp"
#include "src/ui/datatypes/doublespinbox.hpp"

namespace sv {
namespace ui {
namespace datatypes {

DoubleSmallControl::DoubleSmallControl(
		shared_ptr<sv::devices::properties::BaseProperty> property,
		const bool auto_commit, const bool auto_update,
		QString title, QWidget *parent) :
	QGroupBox(parent),
	BaseWidget(property, auto_commit, auto_update),
	title_(title)
{
	setup_ui();
}

void DoubleSmallControl::setup_ui()
{
	this->setTitle(title_);

	QSizePolicy size_policy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	size_policy.setHorizontalStretch(0);
	size_policy.setVerticalStretch(0);
	this->setSizePolicy(size_policy);

	QVBoxLayout *layout = new QVBoxLayout();

	knob_ = new DoubleKnob(property_, true, true);
	layout->addWidget(knob_);

	spin_box_ = new DoubleSpinBox(property_, true, true);
	layout->addWidget(spin_box_);

	this->setLayout(layout);
}

QVariant DoubleSmallControl::variant_value() const
{
	return QVariant(spin_box_->value());
}

} // namespace widgets
} // namespace ui
} // namespace sv
