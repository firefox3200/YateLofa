from plyer import notification

def send_notification(title, message, app_name='Моя программа', timeout=10, icon=None, sound=None, actions=None):
    notification.notify(
        title=title,
        message=message,
        app_name=app_name,
        timeout=timeout,
        app_icon=icon,  # Путь к иконке уведомления
        sound=sound,  # Путь к звуковому файлу для оповещения
        actions=actions  # Действия при щелчке на уведомлении
    )

# Пример отправки уведомления с дополнительными параметрами
send_notification(
    title='Расширенное уведомление',
    message='Это расширенное уведомление с иконкой и звуком!',
    icon='path/to/icon.ico',
    sound='path/to/sound.wav',
    actions=['Open', 'Dismiss']
)