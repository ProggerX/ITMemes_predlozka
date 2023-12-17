#include <iostream>
#include <tgbot/tgbot.h>

using namespace std;

void post(TgBot::Bot& bot, string photo_id, int64_t sender_id) {
	bot.getApi().sendPhoto(getenv("CHANNEL_ID"), photo_id, "Мем из предложки, скинул <a href = 'tg://user?id=" + to_string(sender_id) + "'>вот этот</a> человечек", 0, nullptr, "html");
}

int main() {
    TgBot::Bot bot(getenv("TOKEN"));

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr msg) {
        bot.getApi().sendMessage(msg->chat->id, "Привет! Это предложка канала IT's Memes! Сюда ты можешь скинуть мем(картинкой со сжатием) и он будет опубликован в канале! Однако, если твой мем будет нарушать следующие <a href='https://dg.proggers.ru/other/pravila-predlozhki/'>правила</a>, то тебе конец!", true, 0, nullptr, "html");
    });

	bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr msg) {
		if (msg->photo.size() > 0) {
			post(bot, msg->photo.back()->fileId, msg->chat->id);
		}
	});

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
		cout << "Error: " << e.what() << '\n';
    }
    return 0;
}
