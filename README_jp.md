<h1 align="center">🕹️ Unreal Engine 5 個人ポートフォリオ – アクションゲーム クライアントデモ</h1>
<p align="center">
本プロジェクトは、<strong>Unreal Engine 5.5</strong> を用いた <strong>実践的なクライアント開発経験</strong> を通じて、<br>
<strong>UI・アニメーション・AI・データ駆動設計</strong> への理解を深めることを目的として制作しています。<br>
実際のゲーム開発現場を想定し、ゲームクライアントに必要な各種システムを段階的に設計・実装しながら、<br>
現在も継続して開発を進めている個人プロジェクトです。

</p>

<p align="center">
  <a href="./README.md">English</a> |
  <a href="./README_jp.md">日本語</a>
</p>


## 🌟 ハイライト
<table>
  <tr>
    <th style="text-align:center">인벤토리</th>
    <th style="text-align:center">몬스터 박스</th>
  </tr>
  <tr>
    <td style="text-align:center">
      <img src="https://github.com/user-attachments/assets/7ea1ddb4-0965-4105-9828-984f4c3d8c2a" width="400" height="300">
    </td>
    <td style="text-align:center">
      <img src="https://github.com/user-attachments/assets/cda8c229-92f3-4052-a3a0-d81717911e95" width="400" height="300">
    </td>
  </tr>
  <tr>
    <th style="text-align:center">아이템 박스</th>
    <th style="text-align:center">맵툴</th>
  </tr>
  <tr>
    <td style="text-align:center">
      <img src="https://github.com/user-attachments/assets/2136b6d7-7c41-4c89-9cc6-dc24a8a0a04f" width="400" height="300">
    </td>
    <td style="text-align:center">
      <img src="https://github.com/user-attachments/assets/05c23aa8-aff3-450b-98fb-9cba7951aa53" width="400" height="300">
    </td>
  </tr>
</table>


<br>

## 🔗 リンク
- [プレイ動画](https://youtu.be/Bd5a8q8uKjs)

<br>

## 📜 プロジェクト概要
- **開発期間**：`2025.08.01 ~ 開発中`
- **開発人数**：`1名（個人開発）`
- **使用エンジン**：`Unreal Engine 5.5`
- **担当領域**：`UI`, `アニメーション`, `AI`, `入力システム`, `データ管理`

<br>

## ⚙️ 開発環境
- **使用言語**：`C++17`, `Unreal Blueprint`
- **開発ツール**：`Visual Studio 2022`
- **エンジン**：`Unreal Engine 5.5`

<br>

## ⚒️ 実装内容
- **UI システム**：プレイヤーおよびモンスターの HP / MP 表示、戦闘状況に応じた HUD 切り替え、デリゲートとインターフェースを用いた疎結合な UI 構造を設計・実装。

- **アニメーションシステム**：  
  Animation Montage を用いたコンボ攻撃、Anim Notify による攻撃判定制御、  
  BlendSpace・State Machine を活用した滑らかな移動表現を実装。

- **AI システム**：Behavior Tree / Blackboard を用いた巡回・追跡・攻撃 AI を構築し、行動分岐を設計。

- **入力システム**：  
  Enhanced Input を利用し、アクション・移動・視点切り替えを柔軟に制御。

- **データテーブル管理**：  
  CSV ベースの DataTable を用いたステータス管理構造を設計し、  
  レベル依存データをコードから分離。

<br>

## ⚠️ 注意事項
- 本プロジェクトは **学習および技術検証を目的とした個人開発** です。
- 使用しているアセットはすべて**個人利用およびポートフォリオ用途での使用が許可された無料アセット**のみを使用しています。
- 外部提出用の動画およびドキュメントには、**著作権上の問題が生じる可能性のある要素は含まれていません。**
