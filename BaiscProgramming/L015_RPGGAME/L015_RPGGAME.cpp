#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

// ===== Character 클래스 (기본 클래스) =====
class Character {
protected:
    char name[50];
    int level;
    int hp; 
    int maxHp;
    int mp;
    int maxMp;
    int attack;
    int defense;

public:
    Character(const char* n, int l, int h, int m, int a, int d)
        : level(l), hp(h), maxHp(h), mp(m), maxMp(m), attack(a), defense(d) {
        strcpy(name, n);
    }

    virtual ~Character() {}

    // Getter
    char* GetName() { return name; }
    int GetLevel() { return level; }
    int GetHP() { return hp; }
    int GetMaxHP() { return maxHp; }
    int GetMP() { return mp; }
    int GetMaxMP() { return maxMp; }
    int GetAttack() { return attack; }
    int GetDefense() { return defense; }

    // HP 관리
    void TakeDamage(int damage) {
        int actualDamage = damage - (defense / 2);
        if (actualDamage < 1) actualDamage = 1;
        hp -= actualDamage;
        if (hp < 0) hp = 0;
    }

    void Heal(int amount) {
        hp += amount;
        if (hp > maxHp) hp = maxHp;
    }

    // MP 관리
    void UseMp(int amount) {
        mp -= amount;
        if (mp < 0) mp = 0;
    }

    void RestoreMp(int amount) {
        mp += amount;
        if (mp > maxMp) mp = maxMp;
    }

    // 상태 확인
    bool IsAlive() {
        return hp > 0;
    }

    virtual void ShowStatus() {
        printf("[%s]\n", name);
        printf("  Level: %d\n", level);
        printf("  HP: %d/%d\n", hp, maxHp);
        printf("  MP: %d/%d\n", mp, maxMp);
        printf("  Attack: %d, Defense: %d\n", attack, defense);
    }
};

// ===== Player 클래스 =====
class Player : public Character {
private:
    int experience;
    int nextLevelExp;

public:
    Player(const char* n) 
        : Character(n, 1, 100, 50, 20, 5), experience(0), nextLevelExp(100) {
        printf("[플레이어 생성] %s가 생성되었습니다!\n", name);
    }

    void Attack(Character* target) {
        int damage = attack + (rand() % 10 - 5);
        if (damage < 1) damage = 1;
        
        printf("%s의 공격! -> ", name);
        target->TakeDamage(damage);
        printf("%s에게 %d의 데미지!\n", target->GetName(), damage);
    }

    void Skill(Character* target) {
        if (mp < 20) {
            printf("MP가 부족합니다! (현재 MP: %d)\n", mp);
            return;
        }

        int damage = attack * 2 + (rand() % 20 - 10);
        if (damage < 1) damage = 1;
        
        UseMp(20);
        printf("%s의 스킬 공격! -> ", name);
        target->TakeDamage(damage);
        printf("%s에게 %d의 데미지!\n", target->GetName(), damage);
    }

    void RestoreHealth() {
        if (mp < 10) {
            printf("MP가 부족합니다! (현재 MP: %d)\n", mp);
            return;
        }

        UseMp(10);
        Heal(30);
        printf("%s이(가) 30 HP를 회복했습니다!\n", name);
    }

    void GainExperience(int exp) {
        experience += exp;
        printf("%s이(가) %d의 경험치를 획득했습니다!\n", name, exp);
        printf("현재 경험치: %d/%d\n", experience, nextLevelExp);

        if (experience >= nextLevelExp) {
            LevelUp();
        }
    }

    void LevelUp() {
        level++;
        experience -= nextLevelExp;
        nextLevelExp = level * 100;
        
        maxHp += 30;
        hp = maxHp;
        maxMp += 20;
        mp = maxMp;
        attack += 10;
        defense += 3;

        printf("\n★★★ %s가 레벨 %d로 상승했습니다! ★★★\n", name, level);
        printf("  최대 HP: +30\n");
        printf("  최대 MP: +20\n");
        printf("  공격력: +10\n");
        printf("  방어력: +3\n\n");
    }

    void ShowStatus() override {
        printf("\n=== [%s의 상태] ===\n", name);
        printf("Level: %d\n", level);
        printf("HP: %d/%d\n", hp, maxHp);
        printf("MP: %d/%d\n", mp, maxMp);
        printf("Attack: %d, Defense: %d\n", attack, defense);
        printf("Experience: %d/%d\n", experience, nextLevelExp);
        printf("==================\n\n");
    }
};

// ===== Monster 클래스 =====
class Monster : public Character {
private:
    int dropExp;

public:
    Monster(const char* n, int l, int h, int a, int d, int exp)
        : Character(n, l, h, h, a, d), dropExp(exp) {
        printf("[몬스터 생성] %s(Lv.%d)가 나타났습니다!\n", name, level);
    }

    void Attack(Character* target) {
        int damage = attack + (rand() % 8 - 4);
        if (damage < 1) damage = 1;
        
        printf("%s의 공격! -> ", name);
        target->TakeDamage(damage);
        printf("%s에게 %d의 데미지!\n", target->GetName(), damage);
    }

    int GetDropExp() {
        return dropExp;
    }

    void ShowStatus() override {
        printf("[%s (Lv.%d)]\n", name, level);
        printf("  HP: %d/%d\n", hp, maxHp);
        printf("  Attack: %d, Defense: %d\n", attack, defense);
    }
};

// ===== Battle 클래스 =====
class Battle {
private:
    Player* player;
    Monster* monster;

public:
    Battle(Player* p, Monster* m) : player(p), monster(m) {}

    void StartBattle() {
        printf("\n========== 전투 시작! ==========\n");
        printf("%s VS %s\n", player->GetName(), monster->GetName());
        printf("================================\n\n");

        while (player->IsAlive() && monster->IsAlive()) {
            DisplayBattleMenu();
            
            char choice;
            printf("선택 (1:공격, 2:스킬, 3:회복): ");
            scanf("%c", &choice);
            getchar(); // 엔터키 제거

            switch (choice) {
                case '1':
                    player->Attack(monster);
                    break;
                case '2':
                    player->Skill(monster);
                    break;
                case '3':
                    player->RestoreHealth();
                    break;
                default:
                    printf("잘못된 선택입니다.\n");
                    continue;
            }

            printf("\n");

            if (!monster->IsAlive()) {
                printf("★ %s를 격파했습니다!\n", monster->GetName());
                int exp = monster->GetDropExp();
                player->GainExperience(exp);
                break;
            }

            // 몬스터 공격
            printf("몬스터가 반격합니다!\n");
            monster->Attack(player);
            printf("\n");

            if (!player->IsAlive()) {
                printf("X %s이(가) 쓰러졌습니다...\n", player->GetName());
                break;
            }

            DisplayStatus();
        }

        printf("\n================================\n\n");
    }

    void DisplayBattleMenu() {
        printf("[%s: HP %d/%d, MP %d/%d]\n", 
               player->GetName(), player->GetHP(), player->GetMaxHP(),
               player->GetMP(), player->GetMaxMP());
        printf("[%s: HP %d/%d]\n\n", 
               monster->GetName(), monster->GetHP(), monster->GetMaxHP());
    }

    void DisplayStatus() {
        printf("[%s: HP %d/%d, MP %d/%d]\n", 
               player->GetName(), player->GetHP(), player->GetMaxHP(),
               player->GetMP(), player->GetMaxMP());
        printf("[%s: HP %d/%d]\n\n", 
               monster->GetName(), monster->GetHP(), monster->GetMaxHP());
    }
};

// ===== Monster 팩토리 =====
Monster* CreateRandomMonster() {
    int type = rand() % 3;
    
    switch (type) {
        case 0:
            return new Monster("고블린", 1, 20, 5, 1, 30);
        case 1:
            return new Monster("오크", 2, 40, 10, 3, 60);
        case 2:
            return new Monster("드래곤", 3, 80, 20, 5, 150);
        default:
            return new Monster("슬라임", 1, 15, 3, 0, 20);
    }
}

int main() {
    srand((unsigned)time(0)); //랜덤 seed 생성 

    printf("======================================\n");
    printf("     텍스트 RPG 게임에 오신 것을 환영합니다!\n");
    printf("======================================\n\n");

    // 플레이어 생성
    printf("플레이어 이름을 입력하세요: ");
    char playerName[50];
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = 0;  // 개행문자 제거

    Player* player = new Player(playerName);
    printf("\n");

    // 게임 루프
    char choice = 'Y';
    while (choice != 'Q' && choice != 'q') {
        player->ShowStatus();

        printf("1. 몬스터 사냥\n");
        printf("2. 상태 확인\n");
        printf("Q. 게임 종료\n");
        printf("선택: ");
        scanf("%c", &choice);
        getchar(); // 엔터키 제거

        if (choice == '1') {
            if (!player->IsAlive()) {
                printf("플레이어가 쓰러져 있습니다. 게임을 다시 시작하세요.\n");
                player->Heal(100);
                player->RestoreMp(50);
            }

            Monster* monster = CreateRandomMonster();
            Battle battle(player, monster);
            battle.StartBattle();

            if (!player->IsAlive()) {
                printf("게임 오버!\n");
                break;
            }

            delete monster;
        } 
        else if (choice == '2') {
            player->ShowStatus();
        }
        else if (choice == 'Q' || choice == 'q') {
            printf("\n게임을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 선택입니다.\n\n");
        }
    }

    printf("\n게임 종료. 이용해주셔서 감사합니다!\n");
    delete player;

    return 0;
}