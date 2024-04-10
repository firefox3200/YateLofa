from plyer import notification

def send_notification(title, message, app_name='Моя программа', timeout=10, icon=None, sound=None, actions=None, urgency='normal', image=None, html=None):
    notification.notify(
        title=title,
        message=message,
        app_name=app_name,
        timeout=timeout,
        app_icon=icon,
        sound=sound,
        actions=actions,
        urgency=urgency,
        toast=False,
        image=image,
        html=html  # HTML-разметка для уведомления
    )

# Пример отправки уведомления с HTML-разметкой
html_message = '<h1 style="color: blue;">Привет, мир!</h1><p>Это уведомление с использованием HTML-разметки.</p>'
send_notification(
    title='Уведомление с HTML',
    message='Уведомление с HTML-разметкой',
    icon='path/to/icon.ico',
    html=html_message
)
