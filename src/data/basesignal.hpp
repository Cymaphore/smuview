/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2016 Soeren Apel <soeren@apelpie.net>
 * Copyright (C) 2017 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATA_BASESIGNAL_HPP
#define DATA_BASESIGNAL_HPP

#include <atomic>
#include <condition_variable>
#include <thread>
#include <vector>

#include <QColor>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QTimer>
#include <QVariant>

using std::atomic;
using std::condition_variable;
using std::map;
using std::mutex;
using std::pair;
using std::shared_ptr;
using std::vector;

namespace sigrok {
class Channel;
class Quantity;
class Unit;
}

namespace sv {
namespace data {

class AnalogData;
class BaseData;

class BaseSignal : public QObject
{
	Q_OBJECT

public:
	enum ChannelType {
		AnalogChannel = 1, ///< Analog data
		MathChannel    ///< Virtual channel generated by math operations
	};

public:
	BaseSignal(
		shared_ptr<sigrok::Channel> sr_channel, ChannelType channel_type,
		const sigrok::Quantity *sr_quantity_, QString channel_group_name);
	virtual ~BaseSignal();

public:
	virtual void clear() = 0;
	virtual size_t get_sample_count() const = 0;

	/**
	 * Add a single sample to the signal
	 */
	virtual void push_sample(void *sample,
		 const sigrok::Quantity *sr_quantity, const sigrok::Unit *sr_unit) = 0;

	/**
	 * Add a single sample with timestamp to the signal
	 */
	virtual void push_sample(void *sample, double timestamp,
		const sigrok::Quantity *sr_quantity, const sigrok::Unit *sr_unit) = 0;

	/**
	 * Returns the underlying SR channel.
	 */
	shared_ptr<sigrok::Channel> sr_channel() const;

	/**
	 * Returns the sigrok qunatity of this signal as object
	 */
	const sigrok::Quantity *sr_quantity() const;

	/**
	 * Returns the qunatity of this signal as string
	 */
	QString quantity() const;

	/**
	 * Returns the unit of this signal as string
	 */
	QString unit() const;

	/*
	 * Returns true, when the signal (aka quantity + unit) is is_initialized
	 */
	bool is_initialized() const;

	/**
	 * Returns enabled status of this channel.
	 */
	bool enabled() const;

	/**
	 * Sets the enabled status of this channel.
	 * @param value Boolean value to set.
	 */
	void set_enabled(bool value);

	/**
	 * Gets the type of this channel.
	 */
	ChannelType type() const;

	/**
	 * Gets the index number of this channel, i.e. a unique ID assigned by
	 * the device driver.
	 */
	unsigned int index() const;

	/**
	 * Get the channel group name, the signal is in. Returns "" if the signal
	 * is not in a channel group.
	 *
	 * TODO: Change to vector<QString>, bc the signal can be in more than one
	 *       channel group (see "demo" driver)
	 */
	QString channel_group_name() const;

	/**
	 * Gets the name of this signal.
	 */
	QString name() const;

	/**
	 * Gets the internal name of this signal, i.e. how the device calls it.
	 */
	QString internal_name() const;

	/**
	 * Sets the name of the signal.
	 */
	virtual void set_name(QString name);

	/**
	 * Get the colour of the signal.
	 */
	QColor colour() const;

	/**
	 * Set the colour of the signal.
	 */
	void set_colour(QColor colour);

	virtual void save_settings(QSettings &settings) const;
	virtual void restore_settings(QSettings &settings);

protected:
	void init_quantity(const sigrok::Quantity * sr_quantity);

	shared_ptr<sigrok::Channel> sr_channel_;
	ChannelType channel_type_;

	const sigrok::Quantity *sr_quantity_;
	QString quantity_;
	const sigrok::Unit *sr_unit_;
	QString unit_;
	bool is_initialized_;

	const QString channel_group_name_;
	QString internal_name_; // TODO: const?
	QString name_;
	QColor colour_;

Q_SIGNALS:
	void enabled_changed(const bool &value);
	void name_changed(const QString &name);
	void colour_changed(const QColor &colour);
	/**
	 * When the signal is not initalized, the quantity is emited
	 */
	void quantity_changed(QString);
	/**
	 * When the signal is not initalized, the unit is emited
	 */
	void unit_changed(QString);
};

} // namespace data
} // namespace sv

#endif // DATA_BASESIGNAL_HPP
