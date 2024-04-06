from plyer import notification

# Отправка уведомления
notification.notify(
    title='Пример уведомления',
    message='Это пример уведомления на Windows!',
    app_name='Моя программа',
    timeout=10  # Время отображения уведомления в секундах
)
