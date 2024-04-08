from plyer import notification

def send_notification(title, message, app_name='Моя программа', timeout=10, icon=None, sound=None, actions=None, urgency='normal', image=None):
    notification.notify(
        title=title,
        message=message,
        app_name=app_name,
        timeout=timeout,
        app_icon=icon,
        sound=sound,
        actions=actions,
        urgency=urgency,  # Уровень важности уведомления
        toast=False,  # Отображение уведомления в стиле Windows Toast
        image=image  # Путь к изображению для отображения в уведомлении
    )

# Пример отправки уведомления с дополнительными параметрами
send_notification(
    title='Улучшенное уведомление',
    message='Это улучшенное уведомление с изображением и уровнем важности!',
    icon='path/to/icon.ico',
    sound='path/to/sound.wav',
    actions=['Open', 'Dismiss'],
    urgency='critical',  # Критический уровень важности
    image='path/to/image.png'
)
